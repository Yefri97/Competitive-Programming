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

const int oo = 1e9, mxn = 110;

struct Edge {
	int u, v, w, id;
	Edge() {}
	Edge(int _u, int _v, int _w, int _id) : u(_u), v(_v), w(_w), id(_id) {}
	bool operator < (Edge o) { return w < o.w; }
};

struct UnionFind {
	int p[mxn];
	UnionFind() {}
	void init(int n) { fori(i, 0, n) p[i] = i; }
	int findSet(int i) { return (p[i] == i ? i : p[i] = findSet(p[i])); }
	void unionSet(int i, int j) { p[findSet(i)] = findSet(j); }
};

Edge edges[mxn * mxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		fori(i, 0, m) {
			int u, v, w; cin >> u >> v >> w; u--; v--;
			edges[i] = Edge(u, v, w, i);
		}
		vi mst;
		sort(edges, edges + m);
		// First MST
		UnionFind dsu;
		dsu.init(n);
		int mst_cost1 = 0;
		fori(i, 0, m) {
			Edge e = edges[i];
			if (dsu.findSet(e.u) != dsu.findSet(e.v)) {
				dsu.unionSet(e.u, e.v);
				mst_cost1 += e.w;
				mst.push_back(e.id);
			}
		}
		// Second MST
		int mst_cost2 = oo;
		fori(j, 0, mst.size()) {
			dsu.init(n);
			int cost = 0, numSets = n;
			fori(i, 0, m) {
				Edge e = edges[i];
				if (e.id == mst[j]) continue;
				if (dsu.findSet(e.u) != dsu.findSet(e.v)) {
					dsu.unionSet(e.u, e.v);
					cost += e.w;
					numSets--;
				}
			}
			if (numSets == 1) mst_cost2 = min(mst_cost2, cost);
		}
		cout << mst_cost1 << " " << mst_cost2 << endl;
	}
	return 0;
}