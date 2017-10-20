#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))
#define sq(x) (x) * (x)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int oo = 1e9;

bitset<100010> bs;
vi primes;

void sieve(ll sz) {
	bs.set();
	bs[0] = 0; bs[1] = 0;
	for (ll i = 2; i <= sz; i++) if (bs[i]) {
		for (ll j = i * i; j <= sz; j += i) bs[j] = 0;
		primes.push_back(i);
	}
}

bool is_prime(ll n) {
	if (n <= 100000) return bs[n];
	ll idx = 0, pf = primes[idx];
	while (pf * pf <= n) {
		if (n % pf == 0) return false;
		pf = primes[++idx];
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	sieve(100000);
	ll l, u;
	while (cin >> l >> u) {
		vi ls;
		for (ll i = l; i <= u; i++)
			if (is_prime(i))
				ls.push_back(i);
		if ((int)ls.size() <= 1) {
			cout << "There are no adjacent primes." << endl;
		} else {
			ii ans1, ans2;
			int mmin = oo, mmax = -1;
			fori(i, 1, (int)ls.size()) {
				if (ls[i] - ls[i - 1] < mmin) {
					mmin = ls[i] - ls[i - 1];
					ans1 = ii(ls[i - 1], ls[i]);
				}
				if (ls[i] - ls[i - 1] > mmax) {
					mmax = ls[i] - ls[i - 1];
					ans2 = ii(ls[i - 1], ls[i]);
				}
			}
			cout << ans1.first << "," << ans1.second << " are closest, ";
			cout << ans2.first << "," << ans2.second << " are most distant." << endl;
		}
	}
	return 0;
}