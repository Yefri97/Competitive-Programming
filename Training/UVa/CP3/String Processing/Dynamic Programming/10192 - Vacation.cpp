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

const int oo = 1e9, MX = 110;

int dp[MX][MX];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int cs = 0;
	string a, b;
	while (getline(cin, a) && a != "#") {
		getline(cin, b);
		int n = a.size(), m = b.size();
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				dp[i][j] = dp[i - 1][j - 1] + (a[i - 1] == b[j - 1]);
				dp[i][j] = max(dp[i][j], dp[i - 1][j]);
				dp[i][j] = max(dp[i][j], dp[i][j - 1]);
			}
		}
		cout << "Case #" << ++cs << ": you can visit at most " << dp[n][m] << " cities." << endl;
	}
	return 0;
}