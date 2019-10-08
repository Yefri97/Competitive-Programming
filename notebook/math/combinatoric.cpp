long long C(int n, int k) {
	long long ans = 1;
	for (int i = 1; i <= k; i++, n--) {
		ans = ans * n;
		ans = ans / i;
	}
	return ans;
}