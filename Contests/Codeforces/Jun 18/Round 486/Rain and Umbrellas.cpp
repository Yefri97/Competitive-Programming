#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9, MN = 2010;

int p[MN], w[MN];
int rain[MN], umb[MN];
int dp[MN][MN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int a, n, m; cin >> a >> n >> m;
	fori(i, 1, n + 1) {
		int l, r; cin >> l >> r;
		fori(j, l, r + 1)
			rain[j] = i;
	}
	fori(i, 1, m + 1) {
		cin >> p[i] >> w[i];
		if (umb[p[i]] == 0 || w[umb[p[i]]] > w[i])
			umb[p[i]] = i;
	}
	fori(i, 0, a)
		fori(j, 0, m + 1)
			dp[i][j] = oo;
	if (rain[a]) dp[a][0] = oo;
	for (int i = a - 1; i >= 0; i--) {
		if (i == 0 || rain[i] == 0 || rain[i] != rain[i - 1]) {
			dp[i][0] = dp[i + 1][0];
			if (umb[i]) dp[i][0] = min(dp[i][0], dp[i + 1][umb[i]] + w[umb[i]]);
		}
		for (int j = 1; j <= m; j++) {
			if (i < p[j]) continue;
			dp[i][j] = dp[i + 1][j] + w[j];
			if (rain[i] == 0 || rain[i] != rain[i + 1]) dp[i][j] = min(dp[i][j], dp[i + 1][0]);
			if (umb[i]) dp[i][j] = min(dp[i][j], dp[i + 1][umb[i]] + w[umb[i]]);
		}
	}
	int ans = min(dp[0][0], dp[0][umb[0]]);
	cout << (ans == oo ? -1 : ans) << endl;
	return 0;
}
