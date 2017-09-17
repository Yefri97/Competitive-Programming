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

const int oo = 1e9, mxn = 2510;

int dist[mxn], p[mxn];
vi g[mxn];

int bfs(int s, ii ign) {
	int last;
	memset(dist, -1, sizeof dist); dist[s] = 0;
	queue<int> q; q.push(s);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		last = u;
		fori(i, 0, g[u].size()) {
			int v = g[u][i];
			if ((u == ign.first && v == ign.second) || (u == ign.second && v == ign.first)) continue;
			if (dist[v] == -1) {
				dist[v] = dist[u] + 1;
				p[v] = u;
				q.push(v);
			}
		}
	}
	return last;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vii edges;
		fori(i, 0, n) g[i].clear();
		fori(i, 0, n - 1) {
			int u, v; cin >> u >> v; u--; v--;
			g[u].push_back(v);
			g[v].push_back(u);
			edges.push_back(ii(u, v));
		}
		int ans = oo;
		ii worst, best;
		fori(i, 0, edges.size()) {
			ii e = edges[i];
			int a, b, d1, d2, u1, u2;
			// First subgraph
			a = bfs(e.first, e);
			b = bfs(a, e);
			d1 = dist[b];
			u1 = b;
			fori(i, 0, d1 / 2) u1 = p[u1];
			// Second subgraph
			a = bfs(e.second, e);
			b = bfs(a, e);
			d2 = dist[b];
			u2 = b;
			fori(i, 0, d2 / 2) u2 = p[u2];
			g[u1].push_back(u2);
			g[u2].push_back(u1);
			ii e2 = ((u1 == e.first && u2 == e.second) || (u2 == e.first && u1 == e.second) ? ii(-1, -1) : e);
			a = bfs(0, e2);
			b = bfs(a, e2);
			int val = dist[b];
			if (val < ans) {
				worst = e;
				best = ii(u1, u2);
				ans = val;
			}
			g[u1].pop_back();
			g[u2].pop_back();
		}
		cout << ans << endl;
		cout << worst.first + 1 << " " << worst.second + 1 << endl;
		cout << best.first + 1 << " " << best.second + 1 << endl;
	}
	return 0;
}