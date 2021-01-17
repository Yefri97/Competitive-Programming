long long C(int n, int k) {
	long long ans = 1;
	for (int i = 1; i <= k; i++, n--) {
		ans = ans * n;
		ans = ans / i;
	}
	return ans;
}

// n * k <= 10^7
for (int i = 0; i < MN; i++) {
	C[i][0] = 1; if (i < MK) C[i][i] = 1;
	for (int j = 1; j < min(i, MK))
		C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MD;
}

// n, k <= 10^7
fact[N] * inv_modular(fact[K] * fact[N - K])

// n, k <= 10^18, MD <= 3000
ll lucas(ll n, ll k) {
	ll ans = 1;
	while (n + k) {
		ans = (ans * C[n % MD][k % MD]) % MD;
		n /= MD; k /= MD;
	}
	return ans;
}