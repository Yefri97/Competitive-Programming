#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9, MX = 1000000, MG = 2050;

int LOW;
int A[MX];
ll tree[2][MX];
int nearest[2][MX];

void build(int p, int l, int r) {
	if (l == r) {
		tree[0][p] = tree[1][p] = A[l];
	} else {
		int mid = (l + r) / 2;
		build(2 * p, l, mid);
		build(2 * p + 1, mid + 1, r);
		tree[0][p] = tree[0][2 * p] + tree[0][2 * p + 1];
		tree[1][p] = max(tree[1][2 * p], tree[1][2 * p + 1]);
	}
}

ll query(int p, int l, int r, int i, int j) {
	if (l > j || r < i) return 0;
	if (i <= l && r <= j) return tree[0][p];
	int mid = (l + r) / 2;
	ll q1 = query(2 * p, l, mid, i, j);
	ll q2 = query(2 * p + 1, mid + 1, r, i, j);
	return q1 + q2;
}

void update(int p, int l, int r, int i, int j) {
	if (l > j || r < i) return;
	if (tree[1][p] < 3) return;
	if (l == r) {
		int x = A[l];
		int nx = (x < MX ? nearest[0][x] : nearest[1][x - LOW]);
		A[l] = tree[0][p] = tree[1][p] = x - nx;
		return;
	}
	int mid = (l + r) / 2;
	update(2 * p, l, mid, i, j);
	update(2 * p + 1, mid + 1, r, i, j);
	tree[0][p] = tree[0][2 * p] + tree[0][2 * p + 1];
	tree[1][p] = max(tree[1][2 * p], tree[1][2 * p + 1]);
}

void sieve(int lo, int hi) {
	bitset<MX> bs;
	vi primes;
	bs.set();
	bs[0] = bs[1] = 0;
	for (ll i = 2; i < MX; i++) if (bs[i]) {
		for (ll j = i * i; j < MX; j += i) bs[j] = 0;
		primes.push_back(i);
	}
	for (int i = 0, curr = -1; i < MX; i++) {
		nearest[0][i] = curr;
		if (bs[i]) curr = i;
	}
	bs.set();
	for (int p : primes) {
		for (int i = ((lo + p - 1) / p) * p; i <= hi; i += p)
			bs[i - lo] = 0;
	}
	for (int i = lo, curr = -1; i <= hi; i++) {
		nearest[1][i - lo] = curr;
		if (bs[i - lo])	curr = i;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, q; cin >> n >> q;
	fori(i, 0, n)
		cin >> A[i];
	int lo = *min_element(A, A + n);
	int hi = *max_element(A, A + n);
	LOW = lo = max(2, lo - MG);
	sieve(lo, hi);
	build(1, 0, n - 1);
	while (q--) {
		int t, l, r; cin >> t >> l >> r; l--; r--;
		if (t == 1) {
			update(1, 0, n - 1, l, r);
		} else {
			ll ans = query(1, 0, n - 1, l, r);
			cout << ans << endl;
		}
	}
	return 0;
}
