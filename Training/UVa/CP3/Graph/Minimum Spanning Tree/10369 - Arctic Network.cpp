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

const int oo = 1e9, mxn = 510;

struct Edge {
	int u, v;
	double w;
	Edge() {}
	Edge(int _u, int _v, double _w) : u(_u), v(_v), w(_w) {}
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

double X[mxn], Y[mxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int s, p; cin >> s >> p;
		fori(i, 0, p)
			cin >> X[i] >> Y[i];
		vector<Edge> edges;
		fori(i, 0, p)
			fori(j, 0, i)
				edges.push_back(Edge(i, j, sqrt(sq(X[i] - X[j]) + sq(Y[i] - Y[j]))));
		// Kruskal Algorithm
		sort(edges.begin(), edges.end());
		UnionFind dsu(p);
		double ans = 0;
		int numSets = p;
		fori(i, 0, edges.size()) {
			if (numSets == s) break;
			Edge e = edges[i];
			if (dsu.findSet(e.u) != dsu.findSet(e.v)) {
				dsu.unionSet(e.u, e.v);
				ans = e.w;
				numSets--;
			}
		}
		cout << fixed << setprecision(2) << ans << endl;
	}
	return 0;
}