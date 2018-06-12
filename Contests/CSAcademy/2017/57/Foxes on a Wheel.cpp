#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))
#define sq(x) (x) * (x)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int oo = 1e9;

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
	int n, k; cin >> n >> k;
	vi fox(n);
	UnionFind dsu(n);
	fori(i, 0, k) {
		int f; cin >> f; f--;
		fox[f] = 1;
	}
	fori(i, 0, k) {
		int h; cin >> h; h--;
		if (fox[mod(h - 1, n)]) dsu.unionSet(mod(h - 1, n), h);
		if (fox[mod(h + 1, n)]) dsu.unionSet(mod(h + 1, n), h);
	}
	vi seen(n);
	int ans = 2 * k;
	fori(i, 0, n) {
		int x = dsu.findSet(i);
		if (!seen[x])
			ans -= dsu.sizeOfSet(x) / 2;
		seen[x] = 1;
	}
	cout << ans << endl;
	return 0;
}