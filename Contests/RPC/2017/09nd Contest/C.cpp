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

const int oo = 1e9, mxn = 1010;

int n, m, cc[mxn][mxn], visited[mxn][mxn];
char board[mxn][mxn];
vi value;

int mi[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int mj[] = {-1, 0, 1, 1, 1, 0, -1, -1};

int calc(int i, int j) {
	set<int> st;
	fori(k, 0, 8) {
		int ni = i + mi[k], nj = j + mj[k];
		if (cc[ni][nj] != -1)
			st.insert(cc[ni][nj]);
	}
	int ans = 0;
	for (int x : st)
		ans += value[x];
	return ans;
}

int dfs(int i, int j) {
	visited[i][j] = 1;
	if (board[i][j] == '*') return calc(i, j); 
	int ans = 0;
	fori(k, 0, 8) {
		int ni = i + mi[k], nj = j + mj[k];
		if (ni < 0 || ni > n + 1 || nj < 0 || nj > m + 1) continue;
		if (!visited[ni][nj])
			ans = max(ans, dfs(ni, nj));
	}
	return ans;
}

int flood_fill(int i, int j, int id) {
	cc[i][j] = id;
	int ans = 0;
	fori(k, 0, 8) {
		int ni = i + mi[k], nj = j + mj[k];
		if (ni < 0 || ni > n + 1 || nj < 0 || nj > m + 1 || board[ni][nj] == '*') continue;
		if (cc[ni][nj] == -1)
			ans += flood_fill(ni, nj, id);
	}
	return ans + (board[i][j] == '#');
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	while (cin >> n >> m) {
		fori(i, 0, n + 2) board[i][0] = board[i][m + 1] = '.';
		fori(i, 0, m + 2) board[0][i] = board[n + 1][i] = '.';
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				cin >> board[i][j];
		int id = 0;
		value.clear();
		memset(cc, -1, sizeof cc);
		memset(visited, 0, sizeof visited);
		for (int i = 0; i <= n + 1; i++) {
			for (int j = 0; j <= m + 1; j++) {
				char c = board[i][j];
				if ((c == '#' || c == '.') && cc[i][j] == -1) {
					value.push_back(flood_fill(i, j, id));
					id++;
				}
			}
		}
		int ans = max(value[0], dfs(0, 0));
		cout << ans << endl;
	}
	return 0;
}