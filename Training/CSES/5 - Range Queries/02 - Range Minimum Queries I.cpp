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
const int MN = 200010;
const int ML = 18;
 
int T[MN][ML];
int ln[MN];
 
void build(vi &v) {
	// log2 O(1)
	ln[1] = 0;
	for (int i = 2; i < MN; i++)
		ln[i] = ln[i / 2] + 1;
	// Sparse table
	int n = v.size();
	for (int i = 0; i < n; i++)
		T[i][0] = v[i];
	for (int j = 1, p = 2; p <= n; j++, p <<= 1)
		for (int i = 0; i + p - 1 < n; i++)
			T[i][j] = min(T[i][j - 1], T[i + (p >> 1)][j - 1]);
}
 
int query(int l, int r) {
	int k = ln[r - l + 1];
	return min(T[l][k], T[r + 1 - (1 << k)][k]);
}
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef UTP
	freopen("input.txt", "r", stdin);
	#endif
	int n, q; cin >> n >> q;
	vi a(n);
	fori(i, 0, n) cin >> a[i];
	build(a);
	while (q--) {
		int l, r; cin >> l >> r; l--; r--;
		cout << query(l, r) << endl;
	}
	return 0;
}