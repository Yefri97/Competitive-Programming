#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

bool can(int l, int r, int x) { return l <= x && x <= r; }

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll l, r, x, y; cin >> l >> r >> x >> y;
	int ans = 0;
	for (ll a1 = 1; a1 * a1 <= y; a1++) if ((y % a1) == 0) {
		ll b1 = x * (y / a1);
		ans += (can(l, r, a1) && can(l, r, b1) && __gcd(a1, b1) == x);
		if (a1 * a1 == y) continue;
		ll a2 = y / a1;
		ll b2 = x * (y / a2);
		ans += (can(l, r, a2) && can(l, r, b2) && __gcd(a2, b2) == x);
	}
	cout << ans << endl;
	return 0;
}
