// Non Classical (The Easiser Ones)
#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int INF = 1e9;
int x, board[15][1010], memo[15][1010];

int solver(int i, int j) {
	if (j == x) return (i ? INF : 0);
	if (memo[i][j] != -1) return memo[i][j];
	int ans = solver(i, j + 1) + (30 - board[i][j]);
	if (i < 9) ans = min(ans, solver(i + 1, j + 1) + (60 - board[i][j]));
	if (i > 0) ans = min(ans, solver(i - 1, j + 1) + (20 - board[i][j]));
	return memo[i][j] = ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> x; x /= 100;
		fori(i, 0, 10)
			fori(j, 0, x)
				cin >> board[9 - i][j];
		memset(memo, -1, sizeof memo);
		int ans = solver(0, 0);
		cout << ans << endl << endl;
	}
	return 0;
}