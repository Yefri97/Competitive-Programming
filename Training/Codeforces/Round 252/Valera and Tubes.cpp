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

const int oo = 1e9, MX = 300;

int board[MX][MX];

int di[] = {0, 0, 1};
int dj[] = {1, -1, 0};

int n, m, k;
vector<ii> ans[MX * MX];

void dfs(int i, int j, int cnt) {
	board[i][j] = 1;
	ans[min(cnt >> 1, k - 1)].push_back(ii(i, j));
	for (int k = 0; k < 3; k++) {
		int ni = i + di[k], nj = j + dj[k];
		if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
		if (board[ni][nj] == -1)
			dfs(ni, nj, cnt + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> k;
	memset(board, -1, sizeof board);
	dfs(0, 0, 0);
	fori(i, 0, k) {
		cout << ans[i].size();
		fori(j, 0, (int)ans[i].size())
			cout << " " << ans[i][j].first + 1 << " " << ans[i][j].second + 1;
		cout << endl;
	}
	return 0;
}