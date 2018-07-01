#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9, MX = 60, MD = 1e9 + 7;

ll fact[MX];

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

ll calc(vi &freq) {
	int n = 0;
	fori(i, 0, 10)
		n += freq[i];
	ll c = fact[n - 1];
	fori(i, 0, 10)
		c = (c * fastExp(fact[freq[i]], MD - 2)) % MD;
	ll ans = 0;
	fori(i, 0, n) {
		ll x = 0;
		fori(j, 0, 10)
			x = (x + j * c * freq[j]) % MD;
		ans = (10 * ans + x) % MD;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	fact[0] = 1;
	fori(i, 1, MX)
		fact[i] = (i * fact[i - 1]) % MD;
	int n; cin >> n;
	vi freq(10);
	fori(i, 0, n) {
		int x; cin >> x;
		freq[x]++;
	}
	ll ans = calc(freq);
	if (freq[0] > 0) {
		freq[0]--;
		ans = (ans - calc(freq) + MD) % MD;
	}
	cout << ans << endl;
	return 0;
}
