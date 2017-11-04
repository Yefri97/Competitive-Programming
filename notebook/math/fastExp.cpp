int fastExp(int b, int p) {
	if (p == 0) return 1;
	if (p == 1) return b;
	int ans = fastExp(b, p / 2); ans *= ans;
	if (p % 2 == 1) ans *= b;
	return ans;
}