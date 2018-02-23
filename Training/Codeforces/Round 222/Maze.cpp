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

const int oo = 1e9, MX = 510;

int n, m, k;
int vis[MX][MX];
char board[MX][MX];

int di[] = {0, -1, 0, 1};
int dj[] = {-1, 0, 1, 0};

void dfs(int i, int j) {
	vis[i][j] = 1;
	fori(d, 0, 4) {
		int ni = i + di[d], nj = j + dj[d];
		if (ni < 0 || ni >= n || nj < 0 || nj >= m || board[ni][nj] == '#') continue;
		if (!vis[ni][nj])
			dfs(ni, nj);
	}
	if (k > 0) {
		board[i][j] = 'X';
		k--;
	}
}

void solver() {
	memset(vis, 0, sizeof vis);
	fori(i, 0, n)
		fori(j, 0, m)
			if (board[i][j] == '.') {
				dfs(i, j);
				return;
			}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> k;
	fori(i, 0, n)
		fori(j, 0, m)
			cin >> board[i][j];
	solver();
	fori(i, 0, n) {
		fori(j, 0, m)
			cout << board[i][j];
		cout << endl;
	}
	return 0;
}