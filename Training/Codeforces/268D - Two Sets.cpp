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

const int oo = 1e9, mxn = 100010;

map<int, int> mapper;
int A[mxn], v[mxn], st[mxn];

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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, a, b; cin >> n >> a >> b;
	fori(i, 0, n) {
		int x; cin >> x;
		mapper[x] = i;
		A[i] = x;
	}
	UnionFind dsu(n);
	fori(i, 0, n) {
		if (mapper.count(a - A[i])) dsu.unionSet(i, mapper[a - A[i]]), v[i] |= 1;
		if (mapper.count(b - A[i])) dsu.unionSet(i, mapper[b - A[i]]), v[i] |= 2;
	}
	fori(i, 0, n) st[i] = 3;
	fori(i, 0, n) st[dsu.findSet(i)] &= v[i];
	bool ans = true;
	fori(i, 0, n) ans &= (st[i] != 0);
	if (ans) {
		cout << "YES" << endl;
		fori(i, 0, n) cout << (st[dsu.findSet(i)] != 1) << " ";
		cout << endl;
	} else {
		cout << "NO" << endl;
	}
	return 0;
}