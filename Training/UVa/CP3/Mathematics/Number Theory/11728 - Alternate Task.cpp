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

bitset<1000> bs;
vi primes;

void sieve(int sz) {
	bs.set();
	for (int i = 2; i <= sz; i++) if (bs[i]) {
		for (int j = i * i; j <= sz; j += i) bs[j] = 0;
		primes.push_back(i);
	}
}

int sumDiv(int n) {
	int idx = 0, pf = primes[idx], ans = 1;
	while (pf * pf <= n) {
		int power = 0;
		while (n % pf == 0) { n /= pf; power++; }
		ans *= (pow(pf, power + 1) - 1) / (pf - 1);
		pf = primes[++idx];
	}
	if (n != 1) ans *= n + 1;
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	sieve(1000);
	vi ans(1001, -1);
	fori(i, 0, 1001) {
		int sum = sumDiv(i);
		if (sum <= 1000)
			ans[sum] = i;
	}
	int n, cs = 0;
	while (cin >> n && n)
		cout << "Case " << ++cs << ": " << ans[n] << endl;
	return 0;
}