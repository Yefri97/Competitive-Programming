#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9, MX = 1e5, MN = 510, MD = 1e9 + 7;

int A[MN];
map<int, int> K;

bitset<MX> bs;
vi primes;

void sieve() {
	bs.set();
	bs[0] = bs[1] = 0;
	for (ll i = 2; i < MX; i++) if (bs[i]) {
		for (ll j = i * i; j < MX; j += i)
			bs[j] = 0;
		primes.push_back(i);
	}
}

void fact(ll x) {
	ll idx = 0, pf = primes[idx];
	while (pf * pf <= x) {
		int cnt = 0;
		while (x % pf == 0) { x /= pf; cnt++; }
		K[pf] += cnt;
		pf = primes[++idx];
	}
	if (x > 1)
		K[x]++;
}

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
	sieve();
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		fori(i, 0, n)
			cin >> A[i];
		K.clear();
		fori(i, 0, n)
			fact(A[i]);
		ll a = 1, b = 1;
		for (auto c : K) {
			ll pf = c.first, k = c.second;
			ll x = ((fastExp(pf, k + 2) - 1) * fastExp(pf - 1, MD - 2)) % MD;
			a = (a * ((x - k - 2) % MD + MD) % MD) % MD;
			b = (b * (pf - 1)) % MD;
		}
		ll inv_b = fastExp(b, MD - 2);
		cout << (a * inv_b) % MD << endl;
	}
	return 0;
}