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

const int oo = 1e9, mxn = 110, kmod = 1e6 + 7;

int mj[] = {-1, 1};

int n;
int memo[mxn][mxn];
char board[mxn][mxn];

int solver(int i, int j) {
	if (i == 0) return 1;
	if (memo[i][j] != -1) return memo[i][j];
	int ans = 0;
	fori(k, 0, 2) {
		int ni = i - 1, nj = j + mj[k];
		if (nj < 0 || nj >= n) continue;
		if (board[ni][nj] == 'B') {
			ni = i - 2, nj = j + 2 * mj[k];
			if (ni < 0 || nj < 0 || nj >= n || board[ni][nj] == 'B') continue;
		}
		ans = (ans + solver(ni, nj)) % kmod;
	}
	return memo[i][j] = ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t, cs = 0; cin >> t;
	while (t--) {
		cin >> n;
		ii pos;
		fori(i, 0, n) {
			fori(j, 0, n) {
				char c; cin >> c;
				if (c == 'W') pos = ii(i, j);
				board[i][j] = c;
			}
		}
		memset(memo, -1, sizeof memo);
		int ans = solver(pos.first, pos.second);
		cout << "Case " << ++cs << ": " << ans << endl;
	}
	return 0;
}