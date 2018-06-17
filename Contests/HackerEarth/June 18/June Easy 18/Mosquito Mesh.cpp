#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9, MD = 1e9 + 7, MX = 200010;

ll fact[MX], ifct[MX];

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

ll comb(int n, int k) {
	ll ans = (ifct[k] * ifct[n - k]) % MD;
	return (ans * fact[n]) % MD;
}

ll f(int x, int y) { return comb(x + y, y); }

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	fact[0] = ifct[0] = 1;
	for (ll i = 1; i < MX; i++) {
		fact[i] = (i * fact[i - 1]) % MD;
		ifct[i] = fastExp(fact[i], MD - 2);
	}
	int n, m; cin >> n >> m;
	ll ans = f(n, n);
	fori(i, 0, m) {
		int x, l; cin >> x >> l;
		fori(j, 1, l) {
			ll d = f(x + j, n - x - j);
			ans = ((ans - ((d * d) % MD)) + MD) % MD;
		}
	}
	cout << ans << endl;
	return 0;
}
