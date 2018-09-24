#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define SZ(v) (int)v.size()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, m, q; cin >> n >> m >> q;
	string s, t; cin >> s >> t;
	vi a(n);
	fori(i, 0, n - m + 1)
		a[i] = s.substr(i, m) == t;
	fori(i, 1, n)
		a[i] += a[i - 1];
	while (q--) {
		int l, r; cin >> l >> r; l--; r -= m;
		int ans =  (r < l ? 0 : a[r] - (l > 0 ? a[l - 1] : 0));
		cout << ans << endl;
	}
	return 0;
}
