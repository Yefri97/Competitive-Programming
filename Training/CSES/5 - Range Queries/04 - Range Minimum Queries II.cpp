#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define SZ(X) ((int)X.size())
#define SQ(X) ((X) * (X))
#define all(X) X.begin(), X.end()
#define fori(i,a,b) for(int i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

struct SegmentTree {
	int n;
	vector<int> A, tree;
	SegmentTree(vector<int> _A) : n(SZ(_A)), A(_A) {
		tree.assign(4 * n, 0);
		build(1, 0, n - 1);
	}
	void build(int p, int i, int j) {
		if (i == j) {
			tree[p] = A[i];
		} else {
			int mid = (i + j) / 2;
			build(2 * p, i, mid);
			build(2 * p + 1, mid + 1, j);
			tree[p] = min(tree[2 * p], tree[2 * p + 1]);
		}
	}
	long long query(int p, int i, int j, int L, int R) {
		if (j < L || R < i) return oo;
		if (L <= i && j <= R) return tree[p];
		int mid = (i + j) / 2;
		int q1 = query(2 * p, i, mid, L, R);
		int q2 = query(2 * p + 1, mid + 1, j, L, R);
		return min(q1, q2);
	}
	int query(int i, int j) {
		return query(1, 0, n - 1, i, j);
	}
	void update(int p, int i, int j, int P, int new_value) {
		if (j < P || P < i) return;
		if (P <= i && j <= P) {
			tree[p] = new_value;
			return;
		}
		int mid = (i + j) / 2;
		update(2 * p, i, mid, P, new_value);
		update(2 * p + 1, mid + 1, j, P, new_value);
		tree[p] = min(tree[2 * p], tree[2 * p + 1]);
	}
	void update(int p, int new_value) {
		update(1, 0, n - 1, p, new_value);
	}
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef UTP
	freopen("input.txt", "r", stdin);
	#endif
	int n, q; cin >> n >> q;
	vi a(n);
	for (int &x : a) cin >> x;
	SegmentTree bag(a);
	while (q--) {
		int t; cin >> t;
		if (t == 1) {
			int p; cin >> p; p--;
			int x; cin >> x;
			bag.update(p, x);
		} else {
			int l; cin >> l; l--;
			int r; cin >> r; r--;
			ll ans = bag.query(l, r);
			cout << ans << endl;
		}
	}
	return 0;
}
