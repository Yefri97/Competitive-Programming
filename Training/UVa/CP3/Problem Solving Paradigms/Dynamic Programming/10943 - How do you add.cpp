// Non Classical (The Easiser Ones)
#include <bits/stdc++.h>
using namespace std;

const int max_n = 100;

int memo[max_n + 10][max_n + 10];

int solver(int n, int k) {
	if (k == 1) return 1;
	if (memo[n][k] != -1) return memo[n][k];
	int ans = 0;
	for (int i = 0; i <= n; i++)
		ans = (ans + solver(n - i, k - 1)) % 1000000;
	return memo[n][k] = ans;
}

int main() {
	memset(memo, -1, sizeof memo);
	int n, k;
	while (cin >> n >> k && n + k) {
		int ans = solver(n, k);
		cout << ans << endl;
	}
	return 0;
}