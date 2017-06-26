// Functions involving Prime Factors
#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int INF = 1e9;

bitset<10000010> bs;
vi primes;

void sieve(ll upperbound) {
	ll _sieve_size = upperbound + 1;
	bs.set();
	bs[0] = bs[1] = 0;
	for (ll i = 2; i <= _sieve_size; i++) if (bs[i]) {
		for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
		primes.push_back((int)i);
	}
}

ll numDiv(ll N) {
	ll PF_idx = 0, PF = primes[PF_idx], ans = 1;
	while (PF * PF <= N) {
		ll power = 0;
		while (N % PF == 0) { N /= PF; power++; }
		ans *= (power + 1);
		PF = primes[++PF_idx];
	}
	if (N != 1) ans *= 2;
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	sieve(100000);
	int n; cin >> n;
	while (n--) {
		int l, u; cin >> l >> u;
		int ans, max_val = -1;
		fori(i, l, u + 1) {
			ll val = numDiv(i);
			if (val > max_val) {
				max_val = val;
				ans = i;
			}
		}
		cout << "Between " << l << " and " << u << ", " << ans << " has a maximum of " << max_val << " divisors." << endl;
	}
	return 0;
}