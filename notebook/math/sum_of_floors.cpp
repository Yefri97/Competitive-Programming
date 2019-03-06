// Complexity: O(log(p + q))

// Computes [p/q] + [2p/q] + ... + [np/q]
long long sum_of_floors(long long p, long long q, long long n) {
	if (p == 0 || n == 0) return 0;

	if (n >= q)
		return p * (n / q) * (n + 1) - (n / q) * ((n / q) * p * q + p + q - 1) / 2 + sum_of_floors(p, q, n % q);

	if (p >= q)
		return (p / q) * n * (n + 1) / 2 + sum_of_floors(p % q, q, n);

	return (n * p / q) * n - sum_of_floors(q, p, n * p / q);
}

ans = sum_of_floors(p/g, q/g, n)
