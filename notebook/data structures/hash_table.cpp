/* Hashing */
int base1 = 127, base2 = base1 + 2;
int mod1 = 1e9 + 7, mod2 = mod1 + 2;
ll pow1[MX], pow2[MX];

// Hashing of a vector of bool's of size n
pair<int, int> hash(vector<bool> bs) {
	pow1[0] = pow2[0] = 1;
	for (int i = 1; i < MX; i++) {
		pow1[i] = (base1 * pow1[i - 1]) % mod1;
		pow2[i] = (base2 * pow2[i - 1]) % mod2;
	}
	int n = bs.size(), hval1 = 0, hval2 = 0;
	for (int i = 0; i < n; i++) {
		if (bs[i]) {
			hval1 = (hval1 + pow1[i]) % mod1;
			hval2 = (hval2 + pow2[i]) % mod2;
		}
	}
	return ii(hval1, hval2);
}