// Segment Tree
struct SegmentTree {

	int n;
	vector<long long> A, tree;

	SegmentTree(vector<long long> _A) : n(SZ(_A)), A(_A) {
		tree.assign(4 * n, 0);
		build(1, 0, n - 1);
	}

	void build(int p, int i, int j) {
		if (i == j) {
			tree[p] = i;
		} else {
			int mid = (i + j) / 2;
			build(2 * p, i, mid);
			build(2 * p + 1, mid + 1, j);
			tree[p] = (A[tree[2 * p]] < A[tree[2 * p + 1]] ? tree[2 * p] : tree[2 * p + 1]);
		}
	}

	long long query(int p, int i, int j, int L, int R) {
		if (j < L || R < i) return -1;
		if (L <= i && j <= R) return tree[p];
		int mid = (i + j) / 2;
		long long q1 = query(2 * p, i, mid, L, R);
		long long q2 = query(2 * p + 1, mid + 1, j, L, R);
		if (q1 == -1) return q2;
		if (q2 == -1) return q1;
		return (A[q1] < A[q2] ? q1 : q2);
	}

	long long query(int i, int j) { return query(1, 0, n - 1, i, j); }

	void update(int p, int i, int j, int P, long long new_value) {
		if (j < P || P < i) return;
		if (P <= i && j <= P) {
			A[P] = new_value;
			return;
		}
		int mid = (i + j) / 2;
		update(2 * p, i, mid, P, new_value);
		update(2 * p + 1, mid + 1, j, P, new_value);
		tree[p] = (A[tree[2 * p]] < A[tree[2 * p + 1]] ? tree[2 * p] : tree[2 * p + 1]);
	}

	void update(int p, long long new_value) { update(1, 0, n - 1, p, new_value); }

};

// Segment Tree Lazy Propagation
struct SegmentTree {

	int n;
	vector<long long> tree, lazy;

	SegmentTree(int _n) : n(_n) {
		tree.assign(4 * n, 0);
		lazy.assign(4 * n, 0);
	}

	void pushdown(int p, int i, int j, long long value) {
		tree[p] += value;
		if (i < j) {
			lazy[2 * p] += value;
			lazy[2 * p + 1] += value;
		}
		lazy[p] = 0;
	}

	long long query(int p, int i, int j, int L, int R) {
		if (lazy[p] != 0) pushdown(p, i, j, lazy[p]);
		if (j < L || R < i) return oo;
		if (L <= i && j <= R) return tree[p];
		int mid = (i + j) / 2;
		long long q1 = query(2 * p, i, mid, L, R);
		long long q2 = query(2 * p + 1, mid + 1, j, L, R);
		return min(q1, q2);
	}

	long long query(int i, int j) { return query(1, 0, n - 1, i, j); }

	void update(int p, int i, int j, int L, int R, long long new_value) {
		if (lazy[p] != 0) pushdown(p, i, j, lazy[p]);
		if (j < L || R < i) return;
		if (L <= i && j <= R) {
			pushdown(p, i, j, new_value);
			return;
		}
		int mid = (i + j) / 2;
		update(2 * p, i, mid, L, R, new_value);
		update(2 * p + 1, mid + 1, j, L, R, new_value);
		tree[p] = min(tree[2 * p], tree[2 * p + 1]);
	}

	void update(int i, int j, long long new_value) { update(1, 0, n - 1, i, j, new_value); }

};

// Implicit Lazy Propagation Segment Tree

struct Node {
	Node *l, *r;
	long long value, lazy;
	Node() : l(NULL), r(NULL), value(0), lazy(0) {}
};

Node *root;

void pushdown(Node *p, int i, int j) {
	p->value += (j - i + 1) * p->lazy;
	if (i < j) {
		if (p->l == NULL) p->l = new Node();
		p->l->lazy += p->lazy;
		if (p->r == NULL) p->r = new Node();
		p->r->lazy += p->lazy;
	}
	p->lazy = 0;
}

void update(Node *p, int i, int j, int L, int R, long long inc) {
	if (p->lazy != 0) pushdown(p, i, j);
	if (j < L || R < i) return;
	if (L <= i && j <= R) {
		p->lazy += inc;
		pushdown(p, i, j);
		return;
	}
	int mid = (i + j) / 2;
	if (p->l == NULL) p->l = new Node();
	update(p->l, i, mid, L, R, inc);
	if (p->r == NULL) p->r = new Node();
	update(p->r, mid + 1, j, L, R, inc);
	p->value = p->l->value + p->r->value;
}

long long query(Node *p, int i, int j, int L, int R) {
	if (p == NULL || j < L || R < i) return 0;
	if (p->lazy != 0) pushdown(p, i, j);
	if (L <= i && j <= R) return p->value;
	int mid = (i + j) / 2;
	long long q1 = query(p->l, i, mid, L, R);
	long long q2 = query(p->r, mid + 1, j, L, R);
	return q1 + q2;
}