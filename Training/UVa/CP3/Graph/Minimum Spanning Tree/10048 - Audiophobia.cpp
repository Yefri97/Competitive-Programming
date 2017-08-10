#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))
#define sq(x) (x) * (x)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int oo = 1e9;

struct Edge {
	int u, v, w;
	Edge() {}
	Edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}
	bool operator < (Edge o) { return w < o.w; }
};

struct UnionFind {
	vi p;
	UnionFind(int n) {
		p.assign(n, 0);
		fori(i, 0, n) p[i] = i;
	}
	int findSet(int i) { return (p[i] == i ? i : p[i] = findSet(p[i])); }
	void unionSet(int i, int j) { p[findSet(i)] = findSet(j); }
};

Edge edges[1010];
vii g[110];
int visited[110];

int dfs(int u, int t, int minmax) {
	if (u == t) return minmax;
	visited[u] = 1;
	fori(i, 0, g[u].size()) {
		ii v = g[u][i];
		if (!visited[v.first]) {
			int val = dfs(v.first, t, max(minmax, v.second));
			if (val != -1) return val;
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	bool first = true;
	int n, m, q, cs = 0;
	while (cin >> n >> m >> q && n) {
		if (!first) cout << endl; first = false;
		fori(i, 0, m) {
			int u, v, w; cin >> u >> v >> w; u--; v--;
			edges[i] = Edge(u, v, w);
		}
		// Kruskal Algorithm
		fori(i, 0, n) g[i].clear();
		UnionFind dsu(n);
		sort(edges, edges + m);
		fori(i, 0, m) {
			Edge e = edges[i];
			if (dsu.findSet(e.u) != dsu.findSet(e.v)) {
				dsu.unionSet(e.u, e.v);
				g[e.u].push_back(ii(e.v, e.w));
				g[e.v].push_back(ii(e.u, e.w));
			}
		}
		cout << "Case #" << ++cs << endl;
		while (q--) {
			int s, t; cin >> s >> t; s--; t--;
			memset(visited, 0, sizeof visited);
			int ans = dfs(s, t, 0);
			if (ans == -1)
				cout << "no path" << endl;
			else
				cout << ans << endl;
		}
	}
	return 0;
}