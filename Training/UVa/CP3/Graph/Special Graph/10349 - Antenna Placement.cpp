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

const int oo = 1e9, mxn = 200;

int mi[] = {-1, 0, 1, 0};
int mj[] = {0, 1, 0, -1};

int n, m;
int board[40][10], visited[40][10];
vi id, vis, matched, g[mxn];

int aug(int u) {
	if (vis[u]) return 0;
	vis[u] = 1;
	fori(i, 0, g[u].size()) {
		int v = g[u][i];
		if (matched[v] == -1 || aug(matched[v])) {
			matched[v] = u;
			return 1;
		}
	}
	return 0;
}

void dfs(int i, int j, int color) {
	visited[i][j] = 1;
	fori(k, 0, 4) {
		int ni = i + mi[k], nj = j + mj[k];
		if (ni < 0 || ni >= n || nj < 0 || nj >= m || board[ni][nj] == -2) continue;
		if (board[ni][nj] == -1) board[ni][nj] = id[1 - color]++;
		if (color == 0)
			g[board[i][j]].push_back(board[ni][nj]);
		if (!visited[ni][nj])
			dfs(ni, nj, 1 - color);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> n >> m;
		fori(i, 0, n) {
			fori(j, 0, m) {
				char c; cin >> c;
				board[i][j] = (c == '*' ? -1 : -2);
			}
		}
		fori(i, 0, mxn) g[i].clear();
		id.assign(2, 0);
		memset(visited, 0, sizeof visited);
		fori(i, 0, n) {
			fori(j, 0, m) {
				if (board[i][j] == -1) {
					board[i][j] = id[0]++;
					dfs(i, j, 0);
				}
			}
		}
		int mcbm = 0, V = id[0] + id[1];
		matched.assign(id[1], -1);
		fori(i, 0, id[0]) {
			vis.assign(id[0], 0);
			mcbm += aug(i);
		}
		cout << V - mcbm << endl;
	}
	return 0;
}