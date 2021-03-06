#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9, MN = 5010;

int F[MN][MN], dp[MN][MN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	vi v(n);
	fori(i, 0, n)
		cin >> v[i];
	fori(i, 0, n)
		F[i][1] = dp[i][1] = v[i];
	fori(l, 2, n + 1) {
		fori(i, 0, n - l + 1) {
			F[i][l] = F[i][l - 1] ^ F[i + 1][l - 1];
			dp[i][l] = max(F[i][l], max(dp[i][l - 1], dp[i + 1][l - 1]));
		}
	}
	int q; cin >> q;
	while (q--) {
		int l, r; cin >> l >> r; l--; r--;
		cout << dp[l][r - l + 1] << endl;
	}
	return 0;
}
