#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

int n, m;
ll memo[400][400];
vector<vi> p, s;

ll query(int l, int r) {
	if (n < 400 && memo[l][r] != -1) return memo[l][r];
	vi inv(m);
	fori(i, 0, m)
		inv[s[l - 1][i] - 1] = i + 1;
	ll ans = 0;
	fori(i, 0, m)
		ans += 1LL * (i + 1) * s[r][inv[i] - 1];
	if (n < 400) memo[l][r] = ans;
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> n >> m;
		p.assign(n + 1, vi(m));
		s.assign(n + 1, vi(m));
		fori(i, 1, n + 1)
			fori(j, 0, m)
				cin >> p[i][j];
		fori(j, 0, m)
			s[0][j] = j + 1;
		fori(i, 1, n + 1)
			fori(j, 0, m)
				s[i][j] = p[i][s[i - 1][j] - 1];
		memset(memo, -1, sizeof memo);
		int q; cin >> q;
		while (q--) {
			int l, r; cin >> l >> r;
			ll ans = query(l, r);
			cout << ans << endl;
		}
	}
	return 0;
}
