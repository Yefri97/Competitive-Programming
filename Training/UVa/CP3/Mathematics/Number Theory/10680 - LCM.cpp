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

bitset<2000010> bs;
vi primes;

void sieve(ll sz) {
	bs.set();
	for (ll i = 2; i <= sz; i++) if (bs[i]) {
		for (ll j = i * i; j <= sz; j += i) bs[j] = 0;
		primes.push_back(i);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	sieve(2000000);
	int n;
	while (cin >> n && n) {
		vi exp;
		for (int i = 0, p = primes[0]; p <= n; i++, p = primes[i])
			exp.push_back((int)(log(n) / log(p)));
		int m = exp.size();
		if (m > 2) {
			exp[0] -= exp[2];
			exp[2] = 0;
		}
		int ans = 1;
		fori(i, 0, m)
			ans = (ans * (int)pow(primes[i], exp[i])) % 10;
		cout << ans << endl;
	}
	return 0;
}