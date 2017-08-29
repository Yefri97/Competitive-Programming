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

const int oo = 1e9, mxn = 110;

int n, res[mxn][mxn], p[mxn], f, s, t;

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
			fori(v, 0, n) {
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

int in(int x) { return (x << 1); }
int out(int x) { return (x << 1) + 1; }

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int k, m;
	while (cin >> k >> m && k) {
		memset(res, 0, sizeof res);
		fori(i, 0, k - 2) {
			int id, w; cin >> id >> w; id--;
			res[in(id)][out(id)] += w;
		}
		while (m--) {
			int u, v, w; cin >> u >> v >> w; u--; v--;
			res[out(u)][in(v)] += w;
			res[out(v)][in(u)] += w;
		}
		n = 2 * k;
		s = 1;
		t = n - 2;
		int mf = maxFlow();
		cout << mf << endl;
	}
	return 0;
}