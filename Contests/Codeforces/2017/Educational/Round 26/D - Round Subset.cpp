#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))
#define sq(x) (x) * (x)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int oo = 1e9, mxn = 210, mxt = 25 * mxn;

int dp[2][mxn][mxt];
int cnt2[mxn], cnt5[mxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, k; cin >> n >> k;
	fori(i, 0, n) {
		ll x; cin >> x;
		while (x % 2 == 0) x /= 2, cnt2[i]++;
		while (x % 5 == 0) x /= 5, cnt5[i]++;
	}
	// 0-1 Knapsack Problem Iterative
	memset(dp, -1, sizeof dp);
	int id = 0;
	dp[id][0][0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= k; j++) {
			for (int l = 0; l < mxt; l++) {
				if (dp[id][j][l] == -1) continue;
				if (j + 1 <= k && l + cnt5[i] < mxt)
					dp[1 - id][j + 1][l + cnt5[i]] = max(dp[1 - id][j + 1][l + cnt5[i]], dp[id][j][l] + cnt2[i]);
				dp[1 - id][j][l] = max(dp[1 - id][j][l], dp[id][j][l]);
				dp[id][j][l] = -1;
			}
		}
		id = 1 - id;
	}
	int ans = 0;
	for (int i = 1; i < mxt; i++)
		ans = max(ans, min(i, dp[id][k][i]));
	cout << ans << endl;
	return 0;
}