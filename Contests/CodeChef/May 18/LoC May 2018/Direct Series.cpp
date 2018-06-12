#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9, MD = 1e9 + 7;

ll fastExp(ll b, ll e) {
	ll ans = 1;
	while (e) {
		if (e & 1)
			ans = (ans * b) % MD;
		b = (b * b) % MD;
		e >>= 1;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int q; cin >> q;
	while (q--) {
		ll n, t; cin >> n >> t;
		ll ans = 1;
		for (ll i = 1; i <= t + 1; i++)
			ans = (ans * ((n + i) % MD)) % MD;
		ans = (ans * fastExp(t + 1, MD - 2)) % MD;
		ll c = 1;
		for (ll i = 1; i <= t; i++)
			c = (c * i) % MD;
		ans = (ans - c + MD) % MD;
		cout << ans << endl;
	}
	return 0;
}
