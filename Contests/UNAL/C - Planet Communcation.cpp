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

const int oo = 1e9, mxn = 5010;

ll X[mxn], Y[mxn], Z[mxn];

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

bool collinear(int i, int j) {
	ll a = (sq(X[i]) + sq(Y[i]) + sq(Z[i])) * (sq(X[j]) + sq(Y[j]) + sq(Z[j]));
	ll b = sq(X[i] * X[j] + Y[i] * Y[j] + Z[i] * Z[j]);
	return a == b;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n; n--;
	int xo, yo, zo; cin >> xo >> yo >> zo;
	fori(i, 0, n) {
		int x, y, z; cin >> x >> y >> z;
		X[i] = x - xo;
		Y[i] = y - yo;
		Z[i] = z - zo;
	}
	UnionFind dsu(n);
	fori(i, 0, n)
		fori(j, 0, n)
			if (collinear(i, j))
				dsu.unionSet(i, j);
	cout << dsu.numDisjointSets() << endl;
	return 0;
}