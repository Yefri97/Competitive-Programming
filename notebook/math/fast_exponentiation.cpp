// Recursive
int fastExp(int b, int p) {
	if (p == 0) return 1;
	if (p == 1) return b;
	int ans = fastExp(b, p / 2); ans *= ans;
	if (p % 2 == 1) ans *= b;
	return ans;
}

// Iterative
ll fastExp(ll b, ll e, ll m) {
	ll ans = 1;
	while (e) {
		if (e & 1)
			ans = (ans * b) % m;
		b = (b * b) % m;
		e >>= 1;
	}
	return ans;
}