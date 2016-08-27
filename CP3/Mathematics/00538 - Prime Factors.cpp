#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

vi primes;

void sieve(int n) {
	vi v(n, 1);
	for (int i = 2; i * i <= n; i++) if (v[i])
		for (int j = i * i; j <= n; j += i) v[j] = 0;
	for (int i = 2; i <= n; i++) if (v[i])
		primes.push_back(i);
}

vi primeFactors(ll n) {
	ll p = primes[0];
	vi ans;
	for (int i = 0; p * p <= n; p = primes[++i]) {
		while (n % p == 0) {
			n /= p;
			ans.push_back(p);
		}
	}
	if (n != 1) ans.push_back(n);
	return ans;
}

int main() {
	sieve(100000);
	ll n;
	while (cin >> n && n) {
		cout << n << " = ";
		if (n < 0) cout << "-1 x ";
		n = abs(n);
		vi factors = primeFactors(n);
		for (int i = 0; i < factors.size(); i++) {
			if (i) cout << " x ";
			cout << factors[i];
		}
		cout << endl;
	}
	return 0;
}