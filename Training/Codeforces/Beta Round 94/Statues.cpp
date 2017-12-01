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

const int oo = 1e9, k = 8;

char board[10][10];
int visited[10][10][20];

int mr[] = {-1, -1, 0, 1, 1, 1, 0, -1, 0};
int mc[] = {0, 1, 1, 1, 0, -1, -1, -1, 0};

int dfs(int r, int c, int t) {
	if (r == 0 && c == k - 1) return 1;
	visited[r][c][t] = 1;
	fori(i, 0, 9) {
		int nr = r + mr[i], nc = c + mc[i];
		if (nr >= k || nr < 0 || nc >= k || nc < 0) continue;
		if ((nr - t >= 0 && board[nr - t][nc] == 'S') || (nr - t - 1 >= 0 && board[nr - t - 1][nc] == 'S')) continue;
		if (!visited[nr][nc][t + 1])
			if (dfs(nr, nc, t + 1)) return 1;
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	fori(i, 0, k)
		fori(j, 0, k)
			cin >> board[i][j];
	int ans = dfs(k - 1, 0, 0);
	cout << (ans ? "WIN" : "LOSE") << endl;
	return 0;
}