// checks whether a is a witness that n is not prime, 1 < a < n
bool witness(long long a, long long n) {
	// check as in Miller Rabin Primality Test described
	long long u = n - 1;
	int t = 0;
	while (u % 2 == 0) u /= 2, t++;
	long long last, next = mod_pow(a, u, n);
	if (next == 1) return false;
	for (int i = 0; i < t; ++i) {
		last = next;
		next = mod_mul(last, last, n);
		if (next == 1) return last != n - 1;
	}
	return next != 1;
}

// Checks if a number is prime with prob 1 - 1 / (2 ^ it)
bool miller_rabin(long long n, int it = rounds) {
	if (n <= 1) return false;
	if (n == 2) return true;
	if (n % 2 == 0) return false;
	for (int i = 0; i < it; ++i) {
		long long a = rand() % (n - 1) + 1;
		if (witness(a, n)) return false;
	}
	return true;
}

long long pollard_rho(long long n) {
	long long x, y, i = 1, k = 2, d;
	x = y = rand() % n;
	while (i++) {
		x = mod_mul(x, x, n); x += 2;
		if (x >= n) x -= n;
		if (x == y) return 1;
		d = __gcd(abs(x - y), n);
		if (d != 1) return d;
		if (i == k) y = x, k *= 2;
	}
	return 1;
}

// Returns a list with the prime divisors of n
void factorize(long long n, vector<long long> &pf) {
	if (n == 1) return;
	if (miller_rabin(n)) {
		pf.push_back(n);
	} else {
		long long d = 1;
		while (d == 1) d = pollard_rho(n);
		factorize(d, pf); factorize(n / d, pf);
	}
}