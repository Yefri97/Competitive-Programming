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

int n, m;
char board[mxn][mxn];

int mi[] = {-1, 0, 1, 0};
int mj[] = {0, 1, 0, -1};

int dfs(int i, int j) {
	board[i][j] = 'X';
	int ans = 0;
	fori(k, 0, 4) {
		int ni = i + mi[k], nj = j + mj[k];
		if (ni < 0 || ni > n + 1 || nj < 0 || nj > m + 1 || board[ni][nj] == '1') continue;
		if (board[ni][nj] != 'X')
			ans += dfs(ni, nj);
	}
	return ans + 1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> n >> m;
		fori(i, 0, n + 2) board[i][0] = board[i][m + 1] = '0'; 
		fori(i, 0, m + 2) board[0][i] = board[n + 1][i] = '0';
		fori(i, 0, n)
			fori(j, 0, m)
				cin >> board[i + 1][j + 1];
		cout << dfs(0, 0) - 2 * n - 2 * m - 4 << endl;
	}
	return 0;
}