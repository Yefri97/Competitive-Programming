#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))
#define sq(x) (x) * (x)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int oo = 1e9, MX = 1 << 19;

int A[MX], st[MX];

void build(int p, int L, int R, int depth) {
	if (L == R) {
		st[p] = A[L];
	} else {
		int lp = p << 1, rp = lp + 1, mid = (L + R) >> 1;
		build(lp, L, mid, depth ^ 1);
		build(rp, mid + 1, R, depth ^ 1);
		st[p] = depth ? st[lp] | st[rp] : st[lp] ^ st[rp];
	}
}

int query(int p, int L, int R, int i, int j, int depth) {
	if (R < i || L > j) return -1;
	if (i <= L && R <= j) return st[p];
	int lp = p << 1, rp = lp + 1, mid = (L + R) >> 1;
	int p1 = query(lp, L, mid, i, j, depth ^ 1);
	int p2 = query(rp, mid + 1, R, i, j, depth ^ 1);
	if (p1 == -1) return p2;
	if (p2 == -1) return p1;
	return depth ? st[lp] | st[rp] : st[lp] ^ st[rp];;
}

void update(int p, int L, int R, int pos, int new_value, int depth) {
	if (R < pos || L > pos) return;
	if (L == pos && R == pos) {
		A[pos] = st[p] = new_value;
		return;
	}
	int lp = p << 1, rp = lp + 1, mid = (L + R) >> 1;
	update(lp, L, mid, pos, new_value, depth ^ 1);
	update(rp, mid + 1, R, pos, new_value, depth ^ 1);
	st[p] = depth ? st[lp] | st[rp] : st[lp] ^ st[rp];;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int nn, m; cin >> nn >> m;
	int n = 1 << nn;
	fori(i, 0, n)
		cin >> A[i];
	build(1, 0, n - 1, nn & 1);
	while (m--) {
		int p, x; cin >> p >> x; p--;
		update(1, 0, n - 1, p, x, nn & 1);
		cout << query(1, 0, n - 1, 0, n - 1, nn & 1) << endl;
	}
	return 0;
}