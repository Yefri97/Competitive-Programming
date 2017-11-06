#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))
#define sq(x) (x) * (x)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;

const int oo = 1e9, MX = 100;

int dp[MX][MX];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	for (int i = 0; i < MX; i++) dp[i][0] = dp[0][i] = i;
	int first = 1;
	string a, b;
	while (getline(cin, a)) {
		getline(cin, b);
		if (!first) cout << endl; first = 0;
		int n = a.size(), m = b.size();
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				dp[i][j] = dp[i - 1][j - 1] + (a[i - 1] != b[j - 1]);
				dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
				dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
			}
		}
		vector<iii> ans;
		int i = n, j = m;
		while (i > 0 || j > 0) {
			if (i > 0 && j > 0 && dp[i][j] == dp[i - 1][j - 1] + (a[i - 1] != b[j - 1])) {
				if (a[i - 1] != b[j - 1])
					ans.push_back(iii(0, ii(i, j)));
				i--; j--;
			} else if (i > 0 && dp[i][j] == dp[i - 1][j] + 1) {
				ans.push_back(iii(1, ii(i, j)));
				i--;
			} else {
				ans.push_back(iii(2, ii(i, j)));
				j--;
			}
		}
		cout << dp[n][m] << endl;
		fori(i, 0, (int)ans.size()) {
			cout << i + 1 << " ";
			if (ans[i].first == 0) {
				cout << "Replace " << ans[i].second.first << "," << b[ans[i].second.second - 1];
			}
			if (ans[i].first == 1) {
				cout << "Delete " << ans[i].second.first;
			}
			if (ans[i].first == 2) {
				cout << "Insert " << ans[i].second.first + 1 << "," << b[ans[i].second.second - 1];
			}
			cout << endl;
		}
	}
	return 0;
}