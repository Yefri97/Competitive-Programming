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

void extendedEuclidean(ll a, ll b, ll &d, ll &x, ll &y) {
	if (b == 0) {
		d = a;
		x = 1;
		y = 0;
	} else {
		extendedEuclidean(b, a % b, d, x, y);
		ll x1 = x, y1 = y;
		x = y1;
		y = x1 - (a / b) * y1;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll m, w;
	while (cin >> m >> w) {
		ll n1, n2, n3; cin >> n1 >> n2 >> n3;
		ll d, x, y;
		extendedEuclidean(n1, n2, d, x, y);
		ll ans = 0;
		for (ll c = -m; c <= m; c++) {
			ll wp = w - c * n3;
			if (wp % d) continue;
			ll k = wp / d;
			ll x1 = k * x, y1 = k * y;
			ll l = max(ceil((-m - x1) * d * 1.0 / n2), ceil((y1 - m) * d * 1.0 / n1));
			ll r = min(floor((m - x1) * d * 1.0 / n2), floor((y1 + m) * d * 1.0 / n1));
			ans += max(0LL, r - l + 1);
		}
		cout << ans << endl;
	}
	return 0;
}
