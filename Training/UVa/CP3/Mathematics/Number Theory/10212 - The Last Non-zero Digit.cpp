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

const int oo = 1e9, MX = 20000100;

bitset<MX> bs;
vi primes;

void sieve(ll sz) {
	bs.set();
	for (ll i = 2; i < MX; i++) if (bs[i]) {
		for (ll j = i * i; j < MX; j += i) bs[j] = 0;
		primes.push_back(i);
	}
}

int fastExp(int b, int e, int m) {
	if (e == 0) return 1;
	int res = fastExp(b, e / 2, m); res = (res * res) % m;
	if (e % 2) res = (res * b) % m;
	return res;
}

int solver(ll n, ll k) {
	ll idx = 0, pf = primes[idx];
	vi exp;
	while (pf <= n) {
		int powerN = 0, powerK = 0;
		ll pot = pf;
		while (pot <= n) {
			powerN += n / pot;
			powerK += k / pot;
			pot *= pf;
		}
		exp.push_back(powerN - powerK);
		pf = primes[++idx];
	}
	int m = exp.size();
	if (m > 2) {
		int mmin = min(exp[0], exp[2]);
		exp[0] -= mmin;
		exp[2] -= mmin;
	}
	int ans = 1;
	fori(i, 0, m)
		ans = (ans * fastExp(primes[i], exp[i], 10)) % 10;
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	sieve(MX);
	ll n, m;
	while (cin >> n >> m)
		cout << solver(n, n - m) << endl;
	return 0;
}