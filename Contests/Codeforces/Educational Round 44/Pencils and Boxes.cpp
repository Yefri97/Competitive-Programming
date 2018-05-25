#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

struct FenwickTree {
	int n;
	vi data;
	FenwickTree(int _n) : n(_n), data(vi(n)) {}
	void update(int at, int by) {
		while (at < n) data[at] += by, at |= at + 1;
	}
	int query(int at) {
		int res = 0;
		while (at >= 0) res += data[at], at = (at & (at + 1)) - 1;
		return res;
	}
	int rsq(int a, int b) { return query(b) - query(a - 1); }
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, k, d; cin >> n >> k >> d;
	vi v(n);
	fori(i, 0, n)
		cin >> v[i];
	sort(v.begin(), v.end());
	FenwickTree dp(n);
	for (int i = n - k; i >= 0; i--) {
		int l = i + k;
		int r = upper_bound(v.begin(), v.end(), v[i] + d) - v.begin();
		if (r < l) continue;
		int sum = (r < n ? dp.rsq(l, r) : 1);
		dp.update(i, (sum > 0));
	}
	int ans = dp.rsq(0, 0);
	cout << (ans > 0 ? "YES" : "NO") << endl;
	return 0;
}