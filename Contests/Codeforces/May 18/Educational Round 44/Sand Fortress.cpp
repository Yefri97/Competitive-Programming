#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef unsigned long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const ll oo = 3e9;

ll f1(ll n) { return (n * (n + 1)) / 2; }
ll f2(ll n) { return 2 * f1(n / 2) + (n % 2) * ((n + 1) / 2); }

ll upper(ll x, int b) {
	ll lo = 0, hi = oo;
	while (hi - lo > 1) {
		ll mid = (lo + hi) >> 1;
		ll y = (b == 1) ? f1(mid) : f2(mid);
		if (y > x)
			hi = mid;
		else
			lo = mid;
	}
	return hi;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n, H; cin >> n >> H;
	ll p1 = upper(n, 1); p1--;
	if (p1 <= H) {
		ll ans = p1;
		if (f1(p1) != n)
			ans++;
		cout << ans << endl;
	} else {
		ll p2 = upper(n + f1(H - 1), 2); p2--;
		ll ans = p2 - H + 1;
		if (f2(p2) != n + f1(H - 1))
			ans++;
		cout << ans << endl;
	}
	return 0;
}