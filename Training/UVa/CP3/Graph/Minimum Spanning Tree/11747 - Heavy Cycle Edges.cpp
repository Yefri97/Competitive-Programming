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

const int oo = 1e9, mxn = 25010;

struct edge {
	int w, u, v;
	edge() {}
	edge(int _w, int _u, int _v) : w(_w), u(_u), v(_v) {}
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

edge edges[mxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, m;
	while (cin >> n >> m && n) {
		fori(i, 0, m) {
			int u, v, w; cin >> u >> v >> w;
			edges[i] = edge(w, u, v);
		}
		// Kruskal
		vi ans;
		sort(edges, edges + m);
		UnionFind UF(n);
		fori(i, 0, m) {
			edge e = edges[i];
			if (!UF.isSameSet(e.u, e.v)) {
				UF.unionSet(e.u, e.v);
			} else {
				ans.push_back(e.w);
			}
		}
		if (ans.size()) {
			cout << ans[0];
			fori(i, 1, ans.size())
				cout << " " << ans[i];
			cout << endl;
		} else {
			cout << "forest" << endl;
		}
	}
	return 0;
}