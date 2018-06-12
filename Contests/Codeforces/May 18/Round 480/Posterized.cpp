#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9, MX = 256;

struct UnionFind {
	vi p, size;
	UnionFind(int n) : p(n, -1), size(n, 1) {}
	int findSet(int i) { return (p[i] < 0) ? i : (p[i] = findSet(p[i])); }
	void unionSet(int i, int j) {
		int a = findSet(j), b = findSet(i);
		if (a != b) { p[a] = b; size[b] += size[a]; }
	}
	int sizeSet(int i) { return size[findSet(i)]; }
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, k; cin >> n >> k;
	vi v(n);
	fori(i, 0, n)
		cin >> v[i];
	UnionFind dsu(MX);
	vi ans(n);
	fori(i, 0, n) {
		int x = v[i], y = dsu.findSet(x);
		if (x == y) {
			while (y > 0 && dsu.sizeSet(y - 1) + dsu.sizeSet(x) <= k) {
				dsu.unionSet(y - 1, x);
				y = dsu.findSet(x);
			}
		}
		ans[i] = y;
	}
	fori(i, 0, n)
		cout << ans[i] << " ";
	cout << endl;
	return 0;
}
