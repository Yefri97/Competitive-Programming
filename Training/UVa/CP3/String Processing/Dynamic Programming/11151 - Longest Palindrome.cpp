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
typedef vector<ii> vii;

const int oo = 1e9, MX = 1010;

int dp[MX][MX];

int next_int() {
	string num; getline(cin, num);
	return atoi(num.c_str());
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t = next_int();
	while (t--) {
		string s; getline(cin, s);
		int n = s.size();
		fori(i, 0, n) dp[i][i] = 1;
		for (int l = 2; l <= n; l++) {
			for (int i = 0; i + l <= n; i++) {
				int j = i + l - 1;
				dp[i][j] = s[i] == s[j] ? 2 + dp[i + 1][j - 1] : max(dp[i + 1][j], dp[i][j - 1]);
			}
		}
		cout << dp[0][n - 1] << endl;
	}
	return 0;
}