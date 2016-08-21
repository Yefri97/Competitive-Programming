#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 1;

void init(int v[]) {
	for (int i = 2; i < MAXN; i++) if (!v[i])
		for (int j = i; j < MAXN; j += i) v[j]++;
}

int main() {
	int sieve[MAXN + 10]; memset(sieve, 0, sizeof sieve);
	init(sieve); sieve[1] = 1;
	int n;
	while (cin >> n && n) {
		cout << n << " : " << sieve[n] << endl;
	}
	return 0;
}