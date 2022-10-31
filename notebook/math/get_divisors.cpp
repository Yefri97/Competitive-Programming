void calc_sieve() {
	for (int i = 1; i < MX; i++)
		sieve[i] = i;
	for (int i = 2; i < MX; i++) if (sieve[i] == i) {
		for (int j = i; j < MX; j += i)
			sieve[j] = i;
	}
}

vi get_prime_factors(int n) {
	vi pfs;
	while (n > 1) {
		pfs.push_back(sieve[n]);
		n /= sieve[n];
	}
	pfs.resize(distance(pfs.begin(), unique(all(pfs))));
	return pfs;
}

void get_divisors(vi &divs, int n, vi &pfs, int p) {
	if (p == SZ(pfs)) return divs.push_back(n);
	get_divisors(divs, n, pfs, p + 1);
	while (n % pfs[p] == 0) {
		get_divisors(divs, n / pfs[p], pfs, p + 1);
		n /= pfs[p];
	}
}

void get_divisors(vi &divs, int n) {
	vi pfs = get_prime_factors(n);
	get_divisors(divs, n, pfs, 0);
}