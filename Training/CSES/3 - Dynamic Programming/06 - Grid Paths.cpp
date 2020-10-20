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
const int MD = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef UTP
	freopen("input.txt", "r", stdin);
	#endif
	int n; cin >> n;
	char board[n][n];
	fori(i, 0, n) fori(j, 0, n)
		cin >> board[i][j];
	if (board[0][0] == '*' || board[n - 1][n - 1] == '*') {
		cout << 0 << endl;
		return 0;
	}
	vector<vi> dp(n, vi(n));
	dp[0][0] = 1;
	fori(i, 0, n) fori(j, (i == 0), n) {
		int op1 = 0, op2 = 0;
		if (i > 0 && board[i - 1][j] != '*')
			op1 = dp[i - 1][j];
		if (j > 0 && board[i][j - 1] != '*')
			op2 = dp[i][j - 1];
		dp[i][j] = (op1 + op2) % MD;
	}
	cout << dp[n - 1][n - 1] << endl;
	return 0;
}
