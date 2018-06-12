#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9, MN = 1e5 + 10;

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
	int n, q; cin >> n >> q;
	UnionFind dsu(n);
	vi freq(n + 1);
	freq[1] = n;
	set<int> dict;
	dict.insert(1);
	ll m = n;
	while (q--) {
		int t; cin >> t;
		if (t == 1) {
			int x, y; cin >> x >> y; x--; y--;
			if (dsu.findSet(x) == dsu.findSet(y)) continue;
			int szx = dsu.sizeSet(x);
			freq[szx]--;
			if (freq[szx] == 0) dict.erase(szx);
			int szy = dsu.sizeSet(y);
			freq[szy]--;
			if (freq[szy] == 0) dict.erase(szy);
			dsu.unionSet(x, y);
			int sz = dsu.sizeSet(x);
			freq[sz]++;
			if (freq[sz] == 1) dict.insert(sz);
			m--;
		} else {
			int c; cin >> c;
			if (c == 0) { cout << (m * (m - 1)) / 2 << endl; continue; }
			ll ans = 0, sum = 0;
			auto l = dict.begin(), r = dict.begin();
			while (l != dict.end()) {
				while (r != dict.end() && *(r) < *(l) + c) {
					sum += freq[*(r)];
					r++;
				}
				ans += freq[*(l)] * (m - sum);
				l++;
			}
			cout << ans << endl;
		}
	}
	return 0;
}
