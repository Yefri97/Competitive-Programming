#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define SZ(v) (int)v.size()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

int can(vi &a, vi &b, ll k) {
	if (k == 1) return 0;
	int n = a.size();
	fori(i, 0, n)
		if (a[i] % k && b[i] % k)
			return 0;
	return 1;
}

int solve(vi &a, vi &b) {
	ll x = a[0], y = b[0];
	set<int> dict;
	for (ll i = 2; i * i <= x; i++) if (x % i == 0) {
		while (x % i == 0)
			x /= i;
		dict.insert(i);
	}
	if (x > 1)
		dict.insert(x);
	for (ll i = 2; i * i <= y; i++) if (y % i == 0) {
		while (y % i == 0)
			y /= i;
		dict.insert(i);
	}
	if (y > 1)
		dict.insert(y);
	for (int d : dict)
		if (can(a, b, d))
			return d;
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	vi a(n), b(n);
	fori(i, 0, n)
		cin >> a[i] >> b[i];
	int ans = solve(a, b);
	cout << ans << endl;
	return 0;
}
