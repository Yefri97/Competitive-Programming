#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int oo = 1e9, MN = 110;

int vis[MN];
vii g[MN];

struct UnionFind {
	vi p;
	UnionFind(int n) {
		p.assign(n, 0);
		fori(i, 0, n) p[ i ] = i;
	}
	int findSet( int i ) { return ( p[ i ] == i ) ? i : ( p[ i ] = findSet(p[ i ]) ); }
	void unionSet(int i, int j) { p[ findSet(j) ] = findSet(i); }
};

struct Edge {
	int w, a, b;
	Edge() {}
	Edge(int _w, int _a, int _b) : w(_w), a(_a), b(_b) {}
	bool operator < (const Edge &o) const { return w < o.w; }
};

int mst_kruskal(vector<Edge> &EdgeList, int V, int E) {
	sort(EdgeList.rbegin(), EdgeList.rend());
	int cost = 0;
	UnionFind UF(V);
	fori(i, 0, E) {
		Edge front = EdgeList[i];
		if (UF.findSet(front.a) != UF.findSet(front.b)) {
			cost += front.w;
			UF.unionSet(front.a, front.b);
      g[front.a].push_back(ii(front.b, front.w));
      g[front.b].push_back(ii(front.a, front.w));
		}
	}
	return cost;
}

int dfs(int u, int t) {
  if (u == t) return oo;
  vis[u] = 1;
  fori(i, 0, (int)g[u].size()) {
    ii v = g[u][i];
    if (!vis[v.first]) {
      int x = dfs(v.first, t);
      if (x != -1)
        return min(x, v.second);
    }
  }
  return -1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, m, tc = 0;
  while (cin >> n >> m && n != 0) {
    memset(vis, 0, sizeof vis);
    fori(i, 0, n) g[i].clear();
    vector<Edge> g1;
    fori(i, 0, m) {
      int u, v, w; cin >> u >> v >> w; u--; v--;
      g1.push_back(Edge(w, u, v));
    }
    int s, d, t; cin >> s >> d >> t; s--; d--;
    int mst = mst_kruskal(g1, n, m);
    int x = dfs(s, d);
    int ans = (t + x - 2) / (x - 1);
    cout << "Scenario #" << ++tc << endl;
    cout << "Minimum Number of Trips = " << ans << endl;
    cout << endl;
  }
	return 0;
}
