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

const int oo = 1e9, mxn = 2 * 30 * 30 + 10;

int n, m;
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

int mi[] = {-1, 0, 1, 0};
int mj[] = {0, 1, 0, -1};

int in(int x) { return (x << 1); }
int out(int x) { return (x << 1) + 1; }
int getId(int i, int j) { return (i * m + j); }

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int p;
	while (cin >> n >> m >> p) {
		memset(res, 0, sizeof res);
		V = 2 * n * m + 2;
		s = V - 2;
		t = V - 1;
		fori(i, 0, n) {
			fori(j, 0, m) {
				char c; cin >> c;
				int x = getId(i, j);
				res[in(x)][out(x)] = (c == '~' ? 0 : c == '*' || c == '.' ? 1 : oo);
				if (c == '*') res[s][in(x)] = 1;
				if (c == '#') res[out(x)][t] = p;
			}
		}
		fori(i, 0, n) {
			fori(j, 0, m) {
				fori(k, 0, 4) {
					int ni = i + mi[k], nj = j + mj[k];
					if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
					int u = getId(i, j), v = getId(ni, nj);
					res[out(u)][in(v)] = oo;
					res[out(v)][in(u)] = oo;
				}
			}
		}
		int mf = maxFlow();
		cout << mf << endl;
	}
	return 0;
}