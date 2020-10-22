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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef UTP
	freopen("input.txt", "r", stdin);
	#endif
	int n, x; cin >> n >> x;
	vi w(n), v(n);
	fori(i, 0, n) cin >> w[i];
	fori(i, 0, n) cin >> v[i];
	vector<vi> dp(2, vi(x + 1));
	fori(i, 0, n) fori(j, 0, x + 1) {
		dp[i % 2][j] = dp[(i + 1) % 2][j];
		if (j - w[i] >= 0) {
			int best = dp[(i + 1) % 2][j - w[i]];
			dp[i % 2][j] = max(dp[i % 2][j], best + v[i]);
		}
	}
	int ans = 0;
	fori(i, 0, x + 1)
		ans = max(ans, dp[(n + 1) % 2][i]);
	cout << ans << endl;
	return 0;
}
