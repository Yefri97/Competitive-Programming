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

double X[mxn], Y[mxn];

struct edge {
	double w;
	int u, v;
	edge() {}
	edge(double _w, int _u, int _v) : w(_w), u(_u), v(_v) {}
	bool operator < (edge o) { return w < o.w; }
};

struct UnionFind {
	vi p;
	UnionFind(int n) {
		p.assign(n, 0);
		fori(i, 0, n) p[ i ] = i;
	}
	int findSet( int i ) { return ( p[ i ] == i ) ? i : ( p[ i ] = findSet(p[ i ]) ); }
	void unionSet(int i, int j) { p[ findSet(j) ] = findSet(i); }
};

double dist(int i, int j) { return sqrt(sq(X[i] - X[j]) + sq(Y[i] - Y[j])); }

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		fori(i, 0, n)
			cin >> X[i] >> Y[i];
		vector<edge> edges;
		fori(i, 0, n)
			fori(j, 0, i)
				edges.push_back(edge(dist(i, j), i, j));
		// Kruskal Algorithm
		sort(edges.begin(), edges.end());
		double mst_cost = 0.0;
		UnionFind dsu(n);
		fori(i, 0, edges.size()) {
			edge e = edges[i];
			if (dsu.findSet(e.u) != dsu.findSet(e.v)) {
				dsu.unionSet(e.u, e.v);
				mst_cost += e.w;
			}
		}
		cout << fixed << setprecision(2) << mst_cost << endl;
		if (t) cout << endl;
	}
	return 0;
}