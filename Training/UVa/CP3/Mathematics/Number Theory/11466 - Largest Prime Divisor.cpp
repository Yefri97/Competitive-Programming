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

bitset<10000010> bs;
vi primes;

void sieve(ll sz) {
	bs.set();
	for (ll i = 2; i <= sz; i++) if (bs[i]) {
		for (ll j = i * i; j <= sz; j += i) bs[j] = 0;
		primes.push_back(i);
	}
}

ll solver(ll n) {
	ll idx = 0, pf = primes[idx], nd = 0, ans = -1;
	while (pf * pf <= n) {
		if (n % pf == 0) nd++, ans = pf;
		while (n % pf == 0) n /= pf;
		pf = primes[++idx];
	}
	if (n != 1) nd++, ans = max(ans, n);
	if (nd == 1) return -1;
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	sieve(10000000);
	ll n;
	while (cin >> n && n)
		cout << solver(labs(n)) << endl;
	return 0;
}