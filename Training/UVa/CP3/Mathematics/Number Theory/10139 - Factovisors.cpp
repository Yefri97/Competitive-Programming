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

bool sieve(ll sz) {
	bs.set();
	for (ll i = 2; i <= sz; i++) if (bs[i]) {
		for (ll j = i * i; j <= sz; j += i) bs[j] = 0;
		primes.push_back(i);
	}
}

bool check(ll n, ll m) {
	ll idx = 0, pf = primes[idx];
	while (pf * pf <= m) {
		ll powerM = 0;
		while (m % pf == 0) { m /= pf; powerM++; }
		ll powerN = 0, pot = pf;
		while (pot <= n) { powerN += n / pot; pot *= pf; }
		if (powerM > powerN) return false;
		pf = primes[++idx];
	}
	if (m != 1) {
		ll powerN = 0, pot = m;
		while (pot <= n) { powerN += n / pot; pot *= m; }
		if (1 > powerN) return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	sieve(100000);
	ll n, m;
	while (cin >> n >> m) {
		bool ans = check(n, m);
		cout << m << " " << (ans ? "divides" : "does not divide") << " " << n << "!" << endl;
	}
	return 0;
}