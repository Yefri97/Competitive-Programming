#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))
#define sq(x) (x) * (x)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int oo = 1e9, mxn = 300;

int V, res[mxn][mxn], p[mxn], f, s, t;

void augment(int v, int minEdge) {
	if (v == s) { f = minEdge; return; }
	else if (p[v] != -1) {
		augment(p[v], min(minEdge, res[p[v]][v]));
		res[p[v]][v] -= f; res[v][p[v]] += f;
	}
}

int maxFlow() {
	int mf = 0;
	while (true) {
		f = 0;
		
		vi dist(mxn, oo); dist[s] = 0;
		queue<int> q; q.push(s);
		memset(p, -1, sizeof p);
		while (!q.empty()) {
			int u = q.front(); q.pop();
			if (u == t) break;
			fori(v, 0, V) {
				if (res[u][v] > 0 && dist[v] == oo) {
					dist[v] = dist[u] + 1;
					q.push(v);
					p[v] = u;
				}
			}
		}
		augment(t, oo);
		if (f == 0) break;
		mf += f;
	}
	return mf;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, m, p; cin >> n >> m >> p;
	V = n + m + (p + 1) + 2;
	s = 0;
	t = V - 1;
	fori(i, 0, n) res[s][i + 1] = 1;
	fori(i, 0, n) {
		int k; cin >> k;
		while (k--) {
			int toy; cin >> toy;
			res[i + 1][n + toy] = 1;
		}
	}
	vi taken(m);
	fori(j, 0, p) {
		int k; cin >> k;
		while (k--) {
			int toy; cin >> toy;
			res[n + toy][n + m + j + 1] = 1;
			taken[toy-1] = 1;
		}
		int cap; cin >> cap;
		res[n + m + j + 1][t] = cap;
	}
	fori(i, 0, m)
		if (!taken[i])
			res[n + i + 1][n + m + p + 1] = 1;
	res[n + m + p + 1][t] = oo;
	int mf = maxFlow();
	cout << mf << endl;
	return 0;
}