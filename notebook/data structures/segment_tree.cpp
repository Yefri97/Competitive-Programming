// Segment Tree
const int oo = 1e9, MX = 400000;

int A[MX], st[MX];

void build(int p, int L, int R) {
	if (L == R) {
		st[p] = A[L];
	} else {
		int mid = (L + R) / 2;
		build(2 * p, L, mid);
		build(2 * p + 1, mid + 1, R);
		st[p] = min(st[2 * p], st[2 * p + 1]);
	}
}

int query(int p, int L, int R, int i, int j) {
	if (R < i || L > j) return oo;
	if (i <= L && R <= j) return st[p];
	int mid = (L + R) / 2;
	int q1 = query(2 * p, L, mid, i, j);
	int q2 = query(2 * p + 1, mid + 1, R, i, j);
	return min(q1, q2);
}

void update(int p, int L, int R, int idx, int new_value) {
	if (R < idx || L > idx) return;
	if (L == R) {
		A[idx] = new_value;
		st[p] = new_value;
		return;
	}
	int mid = (L + R) / 2;
	update(2 * p, L, mid, idx, new_value);
	update(2 * p + 1, mid + 1, R, idx, new_value);
	st[p] = min(st[2 * p], st[2 * p + 1]);
}

// Segment Tree Lazy Propagation
struct SegmentTree {

	int n;
	vi A;
	vi tree;
	vi lazy;

	SegmentTree(vi &_A) {
		A = _A;
		n = _A.size();
		tree.assign(4 * n, 0);
		lazy.assign(4 * n, 0);
		build(1, 0, n - 1);
	}

	void build(int p, int i, int j) {
		if (i == j) {
			tree[p] = A[i];
		} else {
			int mid = (i + j) / 2;
			build(2 * p, i, mid);
			build(2 * p + 1, mid + 1, j);
			tree[p] = tree[2 * p] + tree[2 * p + 1];
		}
	}

	int query(int p, int i, int j, int L, int R) {
		if (j < L || R < i) return 0;
		if (lazy[p] != 0) {
			tree[p] += (j - i + 1) * lazy[p];
			if (i < j) {
				lazy[2 * p] += lazy[p];
				lazy[2 * p + 1] += lazy[p];
			}
			lazy[p] = 0;
		}
		if (L <= i && j <= R) return tree[p];
		int mid = (i + j) / 2;
		int q1 = query(2 * p, i, mid, L, R);
		int q2 = query(2 * p + 1, mid + 1, j, L, R);
		return q1 + q2;
	}

	int query(int i, int j) {
		return query(1, 0, n - 1, i, j);
	}

	void update(int p, int i, int j, int L, int R, int new_value) {
		if (lazy[p] != 0) {
			tree[p] += (j - i + 1) * lazy[p];
			if (i < j) {
				lazy[2 * p] += lazy[p];
				lazy[2 * p] += lazy[p];
			}
			lazy[p] = 0;
		}
		if (j < L || R < i) return;
		if (L <= i && j <= R) {
			tree[p] += (j - i + 1) * new_value;
			if (i < j) {
				lazy[2 * p] += new_value;
				lazy[2 * p + 1] += new_value;
			}
			return;
		}
		int mid = (i + j) / 2;
		update(2 * p, i, mid, L, R, new_value);
		update(2 * p + 1, mid + 1, j, L, R, new_value);
		tree[p] = tree[2 * p] + tree[2 * p + 1];
	}

	void update(int i, int j, int new_value) {
		update(1, 0, n - 1, i, j, new_value);
	}

};