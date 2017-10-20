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

bitset<10010> bs;
vi primes;

void sieve(ll sz) {
	bs.set();
	for (ll i = 2; i <= sz; i++) if (bs[i]) {
		for (ll j = i * i; j <= sz; j += i) bs[j] = 0;
		primes.push_back(i);
	}
}

ll solver(ll a, ll c) {
	if (a > c) return -1;
	ll idx = 0, pf = primes[idx], ans = 1;
	while (pf * pf <= c) {
		int powerC = 0, powerA = 0;
		while (c % pf == 0) { c /= pf; powerC++; }
		while (a % pf == 0) { a /= pf; powerA++; }
		if (powerA > powerC) return -1;
		if (powerA < powerC)
			ans *= (ll)pow(pf, powerC);
		pf = primes[++idx];
	}
	if (c != 1) {
		if (a != 1) {
			if (a != c)
				return -1;
		} else {
			ans *= c;
		}
	} else {
		if (a != 1)
			return -1;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	sieve(10000);
	int t; cin >> t;
	while (t--) {
		int a, c; cin >> a >> c;
		int b = solver(a, c);
		if (b == -1)
			cout << "NO SOLUTION" << endl;
		else
			cout << b << endl;
	}
	return 0;
}