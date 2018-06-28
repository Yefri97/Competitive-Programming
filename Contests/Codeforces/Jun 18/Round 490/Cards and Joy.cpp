#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9, MX = 100010;

int c[MX], f[MX];
int dp[510][5010];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, k; cin >> n >> k;
	fori(i, 0, n * k) {
		int x; cin >> x;
		c[x]++;
	}
	fori(i, 0, n) {
		int x; cin >> x;
		f[x]++;
	}
	vi h(k + 1);
	fori(i, 1, k + 1)
		cin >> h[i];
	for (int x = 1; x <= n; x++)
		for (int y = 1; y <= n * k; y++)
			for (int i = 0; i <= k; i++) if (y >= i)
				dp[x][y] = max(dp[x][y], dp[x - 1][y - i] + h[i]);
	ll ans = 0;
	fori(i, 0, MX)
		ans += dp[f[i]][c[i]];
	cout << ans << endl;
	return 0;
}
