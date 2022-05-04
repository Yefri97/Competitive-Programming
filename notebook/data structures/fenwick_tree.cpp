struct FenwickTree { // algo que no esta roto
	int n;
	vector<int> data;
	FenwickTree(int _n) : n(_n), data(vector<int>(n)) {}
	void update(int pos, int inc) {
		while (pos < n) data[pos] += inc, pos |= pos + 1;
	}
	int query(int pos) {
		int res = 0;
		while (pos >= 0) res += data[pos], pos = (pos & (pos + 1)) - 1;
		return res;
	}
	int rsq(int a, int b) { return query(b) - query(a - 1); }
};