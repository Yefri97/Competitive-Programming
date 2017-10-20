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
	for (ll i = 2; i <= sz; i++) if (bs[i]) {
		for (ll j = i * i; j <= sz; j += i) bs[j] = 0;
		primes.push_back(i);
	}
}

ll eulerPhi(ll n) {
	ll idx = 0, pf = primes[idx], ans = n;
	while (pf * pf <= n) {
		if (n % pf == 0) ans -= ans / pf;
		while (n % pf == 0) n /= pf;
		pf = primes[++idx];
	}
	if (n != 1) ans -= ans / n;
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	sieve(100000);
	ll n;
	while (cin >> n && n)
		cout << eulerPhi(n) << endl;
	return 0;
}