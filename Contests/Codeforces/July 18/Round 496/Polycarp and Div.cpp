#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9, MN = 200010;

int dp[MN][3];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	string s; cin >> s;
	int n = s.size();
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < 3; j++) {
			dp[i][j] = dp[i + 1][0] + ((j + (s[i] - '0')) % 3 == 0);
			dp[i][j] = max(dp[i][j], dp[i + 1][(j + (s[i] - '0')) % 3]);
		}
	}
	cout << dp[0][0] << endl;
	return 0;
}
