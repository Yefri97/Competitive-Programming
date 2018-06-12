#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int INF = 1e9, MAXN = 1010;

int input[MAXN], memo[MAXN][MAXN];

class UnionFind {
private:
	vi p, rank, setSize;
	int numSets;
public:
	UnionFind() {}
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

UnionFind dsu;

int solver(int l, int r) {
	if (l == r) return 1;
	if (l + 1 == r) return dsu.isSameSet(input[l], input[r]) ? 2 : 1;
	if (memo[l][r] != -1) return memo[l][r];
	if (dsu.isSameSet(input[l], input[r]))	return memo[l][r] = solver(l + 1, r - 1) + 2;
	return memo[l][r] = max(solver(l + 1, r), solver(l, r - 1));
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, k, m; cin >> n >> k >> m;
	dsu = UnionFind(n + 1);
	while (k--) {
		int a, b; cin >> a >> b;
		dsu.unionSet(a, b);
	}
	fori(i, 0, m)
		cin >> input[i];
	memset(memo, -1, sizeof memo);
	int ans = solver(0, m - 1);
	cout << ans << endl;
	return 0;
}