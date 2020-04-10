/*	Euler's Totient Function:
Counts the number of integers k in the range 1 <= k < n && gcd(k, n) == 1
eulerPhi(n / d) = number of integers k such that gcd(k, n) == d */
long long euler_phi(long long n) {
	long long p = 2, ans = n;
	while (p * p <= n) {
		if (n % p == 0) ans -= ans / p;
		while (n % p == 0) n /= p;
		p++;
	}
	if (n != 1) ans -= ans / n;
	return ans;
}
void calc_euler_phi() {
	for (int i = 1; i < MX; i++)
		phi[i] = i;
	for (int i = 2; i < MX; i++) if (phi[i] == i) {
		for (int j = i; j < MX; j += i)
			phi[j] = (phi[j] / i) * (i - 1);
	}
}
/* Pillai's arithmetical function:
pillai(n) = sum{gcd(k, n)} | 1 <= k <= n
pillai(n) = sum{d * phi(n / d)} | n % d == 0 */
long long calc_pillai(long long n) {
	for (int i = 1; i < MX; i++) {
		int phi = euler_phi(i);
		for (int j = 1; j * i < MX; j++)
			pillai[j * i] += j * phi;
	}
}