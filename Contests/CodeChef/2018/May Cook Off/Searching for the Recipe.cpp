#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9, MN = 310, MOD = 1e9 + 7;

int n, m;
char board[MN][MN];
int up[MN][MN], dw[MN][MN];
int dp[5][MN][MN], sum[MN][MN];

void update(int k) {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			sum[i][j] = dp[k][i - 1][j - 1];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			sum[i][j] = (sum[i][j] + sum[i - 1][j]) % MOD;
			sum[i][j] = (sum[i][j] + sum[i][j - 1]) % MOD;
			sum[i][j] = (sum[i][j] - sum[i - 1][j - 1] + MOD) % MOD;
		}
	}
}

int doit(int k, int c, int x, int y) {
	int r1 = up[c][x] + 1, r2 = min(y, dw[c][x]) - 1; r1++, r2++;
	int c1 = max(x, up[c][y]) + 1, c2 = dw[c][y] - 1; c1++, c2++;
	int ans = 0;
	ans = (ans + sum[r2][c2]) % MOD;
	ans = (ans - sum[r2][c1 - 1] + MOD) % MOD;
	ans = (ans - sum[r1 - 1][c2] + MOD) % MOD;
	ans = (ans + sum[r1 - 1][c1 - 1]) % MOD;
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> n >> m;
		fori(i, 0, n)
			fori(j, 0, m)
				cin >> board[i][j];
		fori(c, 0, m) {
			int a = -1, b = n;
			fori(r, 0, n) {
				up[c][r] = a;
				dw[c][n - r - 1] = b;
				if (board[r][c] == '#') a = r;
				if (board[n - r - 1][c] == '#') b = n - r - 1;
			}
		}
		memset(dp, 0, sizeof dp);
		fori(i, 0, dw[m - 1][0])
			fori(j, max(i, up[m - 1][n - 1]) + 1, n)
				dp[0][i][j] = 1;
		update(0);
		int curr = 1;
		for (int c = m - 2; c >= 0; c--) {
			fori(i, 0, n) {
				fori(j, i + 1, n) {
					if (board[i][c] == '#' || board[j][c] == '#')
						dp[curr][i][j] = 0;
					else
						dp[curr][i][j] = doit(1 - curr, c, i, j);
				}
			}
			update(curr);
			curr = 1 - curr;
		}
		cout << dp[1 - curr][0][n - 1] << endl;
	}
	return 0;
}
