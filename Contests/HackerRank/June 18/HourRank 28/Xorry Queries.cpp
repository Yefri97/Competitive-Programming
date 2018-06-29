#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9, MX = 18;

struct SegmentTree {

	int n;
	vi A;
	vi tree;
	vi lazy;

	SegmentTree() {}

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
			if (lazy[p] % 2)
				tree[p] = (j - i + 1) - tree[p];
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
		if (i > j) return 0;
		return query(1, 0, n - 1, i, j);
	}

	void update(int p, int i, int j, int L, int R, int new_value) {
		if (lazy[p] != 0) {
			if (lazy[p] % 2)
				tree[p] = (j - i + 1) - tree[p];
			if (i < j) {
				lazy[2 * p] += lazy[p];
				lazy[2 * p + 1] += lazy[p];
			}
			lazy[p] = 0;
		}
		if (j < L || R < i) return;
		if (L <= i && j <= R) {
			tree[p] = (j - i + 1) - tree[p];
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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, m; cin >> n >> m;
	int p; cin >> p;
	vi a(n), s(n - p + 1);
	fori(i, 0, n)
		cin >> a[i];
	int xorry = 0;
	for (int l = 0, r = 0; r < n; l++) {
		while (r < n && r - l < p) xorry ^= a[r++];
		s[l] = xorry;
		xorry ^= a[l];
	}
	vector<SegmentTree> st(MX);
	fori(i, 0, MX) {
		vi bits(n - p + 1);
		fori(j, 0, n - p + 1)
			bits[j] = (s[j] >> i) & 1;
		st[i] = SegmentTree(bits);
	}
	while (m--) {
		int q; cin >> q;
		if (q == 1) {
			int idx, x; cin >> idx >> x; idx--;
			int l = max(0, idx - p + 1);
			int r = idx;
			fori(i, 0, MX) if ((x >> i) & 1)
				st[i].update(l, r, 1);
		} else {
			int l, r; cin >> l >> r; l--; r--;
			r = min(r, n - p + 1);
			ll ans = 0;
			fori(i, 0, MX)
				ans += (1LL * st[i].query(l, r) * (1LL << i));
			cout << ans << endl;
		}
	}
	return 0;
}
