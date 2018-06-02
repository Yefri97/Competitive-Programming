#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9, MX = 1000010, MD = 998244353;

ll fact[MX];

ll fastExp(ll b, ll e) {
	ll ans = 1;
	while (e > 0) {
		if (e & 1)
			ans = (ans * b) % MD;
		b = (b * b) % MD;
		e >>= 1;
	}
	return ans;
}

ll comb(ll n, ll k) {
	ll ans = 1;
	ans = (ans * fact[n]) % MD;
	ans = (ans * fastExp(fact[k], MD - 2)) % MD;
	ans = (ans * fastExp(fact[n - k], MD - 2)) % MD;
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	fact[0] = 1;
	for (ll i = 1; i < MX; i++)
		fact[i] = (i * fact[i - 1]) % MD;
	ll n, m;
	while (cin >> n >> m) {
		ll ans = 0;
		fori(k, 0, n + 1) {
			ll c = (comb(n, k) * fastExp(fastExp(2, n - k) - 1, m)) % MD;
			if (k & 1) ans = (ans - c + MD) % MD;
			else ans = (ans + c) % MD;
		}
		cout << ans << endl;
	}
	return 0;
}
