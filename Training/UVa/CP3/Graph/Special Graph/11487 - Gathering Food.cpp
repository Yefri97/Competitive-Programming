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

const int oo = 1e9, mxn = 15, kmod = 20437;

int n, memo[mxn][mxn][mxn * mxn];
char board[mxn][mxn];
ii pos[30];

int mi[] = {-1, 0, 1, 0};
int mj[] = {0, 1, 0, -1};

int countPaths(int i, int j, int c, int t) {
	if (i == pos[t].first && j == pos[t].second) return (c == 0);
	if (c <= 0) return 0;
	if (memo[i][j][c] != -1) return memo[i][j][c];
	int ans = 0;
	fori(k, 0, 4) {
		int ni = i + mi[k], nj = j + mj[k];
		if (ni < 0 || ni >= n || nj < 0 || nj >= n || board[ni][nj] == '#') continue;
		ans = (ans + countPaths(ni, nj, c - 1, t)) % kmod;
	}
	return memo[i][j][c] = ans;
}

int bfs(int s, int t) {
	vvi dist(n, vi(n, oo)); dist[pos[s].first][pos[s].second] = 0;
	queue<ii> q; q.push(pos[s]);
	while (!q.empty()) {
		ii u = q.front(); q.pop();
		int i = u.first, j = u.second;
		fori(k, 0, 4) {
			int ni = i + mi[k], nj = j + mj[k];
			if (ni < 0 || ni >= n || nj < 0 || nj >= n || board[ni][nj] == '#') continue;
			if (dist[ni][nj] == oo) {
				dist[ni][nj] = dist[i][j] + 1;
				q.push(ii(ni, nj));
			}
		}
	}
	return dist[pos[t].first][pos[t].second];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int cs = 0;
	while (cin >> n && n) {
		int m = 0;
		fori(i, 0, n) {
			fori(j, 0, n) {
				char c; cin >> c;
				if (isalpha(c)) {
					int id = c - 'A';
					pos[id] = ii(i, j);
					m = max(m, id);
					c = '#';
				}
				board[i][j] = c;
			}
		}
		bool b = true;
		board[pos[0].first][pos[0].second] = '.';
		fori(i, 0, m) {
			board[pos[i + 1].first][pos[i + 1].second] = '.';
			if (bfs(i, i + 1) == oo)
				b = false;
		}
		fori(i, 0, m + 1) board[pos[i].first][pos[i].second] = '#';
		cout << "Case " << ++cs << ": ";
		if (b) {
			int sp = 0, ans = 1;
			board[pos[0].first][pos[0].second] = '.';
			fori(i, 0, m) {
				board[pos[i + 1].first][pos[i + 1].second] = '.';
				int c = bfs(i, i + 1);
				sp += c;
				memset(memo, -1, sizeof memo);
				int x = countPaths(pos[i].first, pos[i].second, c, i + 1);
				ans = (ans * x) % kmod;
			}
			cout << sp << " " << ans << endl;
		} else {
			cout << "Impossible" << endl;
		}
	}
	return 0;
}