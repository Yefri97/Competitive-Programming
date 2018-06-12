#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9, MX = 2000001, MD = 1e9 + 7;

int cnt;
int pf[MX], sum[MX], d[MX];
ll fact[MX], ifct[MX];
bitset<MX> bs;

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

void precalc(int mx) {
	fact[0] = ifct[0] = 1;
	for (ll i = 1; i < mx; i++) {
		fact[i] = (i * fact[i - 1]) % MD;
		ifct[i] = fastExp(fact[i], MD - 2);
	}
}

ll comb(ll n, ll k) {
	ll ans = (fact[n] * ((ifct[k] * ifct[n - k]) % MD)) % MD;
	return ans;
}

void sieve(int n) {
	bs.set();
	for (int i = 2; i <= n; i++) if (bs[i]) {
		for (int j = i; j <= n; j += i) {
			if (j != i) bs[j] = 0;
			d[j] = i;
			pf[j]++;
			sum[j] = sum[j / i] + 1;
		}
	}
	for (int i = 2; i <= n; i++)
		cnt += bs[i];
}

ll doit(int curr, int div, int n, int k) {
	if (curr == 1) {
		int a = cnt - pf[div];
		int b = k - sum[div];
		ll res = (b < 0 ? 0LL : comb(a + b, a));
		return res;
	}
	int to = curr, c = 0;
	while (d[to] == d[curr]) {
		to /= d[curr];
		c++;
	}
	ll q = 0;
	int x = div;
	fori(i, 0, c + 1) {
		q = (q + doit(to, x, n, k)) % MD;
		x *= d[curr];
	}
	return q;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, k; cin >> n >> k;
	sieve(n);
	precalc(n + k + 1);
	ll ans = 0;
	for (ll i = 1; i <= n; i++) {
		ll q = doit(i, 1, i, k);
		ans = (ans + i * q) % MD;
	}
	cout << ans << endl;
	return 0;
}
