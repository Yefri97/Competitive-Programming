#include <bits/stdc++.h>

using namespace std;

const unsigned MAXN = 1000000;

int sieve[MAXN + 10];

void init_sieve() {
	for (int i = 2; i * i <= MAXN; i++) if (sieve[i])
		for (int j = i * i; j <= MAXN; j += i)
			sieve[j] = 0;
}

int main() {
	memset(sieve, 1, sizeof sieve);
	init_sieve();
	int n;
	while (cin >> n && n) {
		int ans = -1;
		for (int i = 2; i < MAXN && ans == -1; i++) 
			if (sieve[i] && sieve[n - i]) ans = i;
		cout << n << " = " << ans << " + " << n - ans << endl;
	}
	return 0;
}