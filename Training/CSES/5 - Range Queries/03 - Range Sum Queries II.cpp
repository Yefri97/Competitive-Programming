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
const int MN = 2e5 + 10;

long long tree[4 * MN];

long long query(int p, int i, int j, int L, int R) {
	if (j < L || R < i) return 0;
	if (L <= i && j <= R) return tree[p];
	int mid = (i + j) / 2;
	long long q1 = query(2 * p, i, mid, L, R);
	long long q2 = query(2 * p + 1, mid + 1, j, L, R);
	return q1 + q2;
}

void update(int p, int i, int j, int P, long long new_value) {
	if (j < P || P < i) return;
	if (P <= i && j <= P) {
		tree[p] = new_value;
		return;
	}
	int mid = (i + j) / 2;
	update(2 * p, i, mid, P, new_value);
	update(2 * p + 1, mid + 1, j, P, new_value);
	tree[p] = tree[2 * p] + tree[2 * p + 1];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef UTP
	freopen("input.txt", "r", stdin);
	#endif
	int n, q; cin >> n >> q;
	fori(i, 0, n) {
		int x; cin >> x;
		update(1, 0, n - 1, i, x);
	}
	while (q--) {
		int t; cin >> t;
		if (t == 1) {
			int p; cin >> p; p--;
			int x; cin >> x;
			update(1, 0, n - 1, p, x);
		} else {
			int l; cin >> l; l--;
			int r; cin >> r; r--;
			ll ans = query(1, 0, n - 1, l, r);
			cout << ans << endl;
		}
	}
	return 0;
}
