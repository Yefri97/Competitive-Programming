#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9, MN = 1010, MD = 1e9 + 7;

char grid[3][MN];
int dp[3][MN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int tc; cin >> tc;
	fori(t, 0, tc) {
		int n; cin >> n;
		fori(i, 0, 3)
			fori(j, 0, n)
				cin >> grid[i][j];
		memset(dp, 0, sizeof dp);
		dp[2][n] = 1;
		for (int i = n - 1; i >= 0; i--) {
			if (grid[0][i] == '.' && grid[1][i] == '.')
				dp[0][i] = (dp[0][i] + dp[1][i + 1]) % MD;
			if (grid[1][i] == '.' && grid[0][i] == '.')
				dp[1][i] = (dp[1][i] + dp[0][i + 1]) % MD;
			if (grid[1][i] == '.' && grid[2][i] == '.')
				dp[1][i] = (dp[1][i] + dp[2][i + 1]) % MD;
			if (grid[2][i] == '.' && grid[1][i] == '.')
				dp[2][i] = (dp[2][i] + dp[1][i + 1]) % MD;
		}
		int ans = dp[0][0];
		cout << "Case #" << t + 1 << ": " << ans << endl;
	}
	return 0;
}
