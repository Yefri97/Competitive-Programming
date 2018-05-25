struct FenwickTree {
	int n;
	vi data;
	FenwickTree(int _n) : n(_n), data(vi(n)) {}
	void update(int at, int by) {
		while (at < n) data[at] += by, at |= at + 1;
	}
	int query(int at) {
		int res = 0;
		while (at >= 0) res += data[at], at = (at & (at + 1)) - 1;
		return res;
	}
	int rsq(int a, int b) { return query(b) - query(a - 1); }
};