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
	int n; cin >> n;
	vi v(n);
	fori(i, 0, n) {
		cin >> v[i];
		v[i]--;
	}
	FenwickTree ft(n);
	ll ans = 0;
	for (int x : v) {
		ans += ft.rsq(x, n - 1);
		ft.update(x, 1);
	}
	cout << ((n % 2 == ans % 2) ? "Petr" : "Um_nik") << endl;
	return 0;
}
