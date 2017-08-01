#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))
#define sq(x) (x) * (x)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<double, int> ii;
typedef vector<ii> vii;

const int oo = 1e9, mxn = 1010;

int n, r;
int X[mxn], Y[mxn];

struct edge {
	double w;
	int u, v;
	edge() {}
	edge(double _w, int _u, int _v) : w(_w), u(_u), v(_v) {}
	bool operator < (edge o) { return w < o.w; }
};

class UnionFind {
private:
	vi p, rank, setSize;
	int numSets;
public:
	UnionFind(int N) {
		setSize.assign(N, 1); numSets = N; rank.assign(N, 0);
		p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i; }
	int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
	bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
	void unionSet(int i, int j) {
		if (!isSameSet(i, j)) { numSets--;
		int x = findSet(i), y = findSet(j);
		if (rank[x] > rank[y]) { p[y] = x; setSize[x] += setSize[y]; }
		else                   { p[x] = y; setSize[y] += setSize[x];
														if (rank[x] == rank[y]) rank[y]++; } } }
	int numDisjointSets() { return numSets; }
	int sizeOfSet(int i) { return setSize[findSet(i)]; }
};

double dist(int a, int b) { return sqrt(sq(X[a] - X[b]) + sq(Y[a] - Y[b])); }

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t, cs = 0; cin >> t;
	while (t--) {
		cin >> n >> r;
		fori(i, 0, n)
			cin >> X[i] >> Y[i];
		// Kruskal
		vector<edge> edges;
		fori(i, 0, n)
			fori(j, 0, n)
				if (i != j)
					edges.push_back(edge(dist(i, j), i, j));
		sort(edges.begin(), edges.end());
		double road = 0.0, rail = 0.0;
		int numstates = 1;
		UnionFind UF(n);
		fori(i, 0, edges.size()) {
			edge e = edges[i];
			if (!UF.isSameSet(e.u, e.v)) {
				if (e.w > r) rail += e.w, numstates++;
				else road += e.w;
				UF.unionSet(e.u, e.v);
			}
		}
		cout << "Case #" << ++cs << ": " << numstates << " " << round(road) << " " << round(rail) << endl;
	}
	return 0;
}