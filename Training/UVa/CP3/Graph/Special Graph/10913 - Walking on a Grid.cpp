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

const int oo = 1e9, mxn = 100;

int n;
int board[mxn][mxn];
int flag, visited[mxn][mxn][10][5], memo[mxn][mxn][10][5];

int mj[] = {-1, 1};

int solver(int i, int j, int res, int dir) {
	if (res < 0) return -oo;
	if (i == n - 1 && j == n - 1) { flag = true; return board[n - 1][n - 1]; }
	if (visited[i][j][res][dir]) return memo[i][j][res][dir];
	int ans = -oo;
	if (i + 1 < n)
		ans = max(solver(i + 1, j, res - (board[i + 1][j] < 0), 0), 
							solver(i + 1, j, res - (board[i + 1][j] < 0), 1));
	if (j + mj[dir] >= 0 && j + mj[dir] < n)
		ans = max(ans, solver(i, j + mj[dir], res - (board[i][j + mj[dir]] < 0), dir));
	visited[i][j][res][dir] = 1;
	return memo[i][j][res][dir] = ans + board[i][j];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int k, cs = 0;
	while (cin >> n >> k && n) {
		fori(i, 0, n)
			fori(j, 0, n)
				cin >> board[i][j];
		flag = false;
		memset(visited, 0, sizeof visited);
		int ans = solver(0, 0, k - (board[0][0] < 0), 1);
		cout << "Case " << ++cs << ": ";
		if (flag)
			cout << ans << endl;
		else
			cout << "impossible" << endl;
	}
	return 0;
}