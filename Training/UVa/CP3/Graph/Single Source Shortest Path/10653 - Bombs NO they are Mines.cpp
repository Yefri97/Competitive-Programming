#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))
#define sq(x) (x) * (x)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int oo = 1e9, mxn = 1010;

int mi[] = {-1, 0, 1, 0};
int mj[] = {0, 1, 0, -1};

int n, m;
char board[mxn][mxn];

int solver(ii s, ii t) {
	vector<vi> dist(n, vi(m, oo)); dist[s.first][s.second] = 0;
	queue<ii> q; q.push(s);
	while (!q.empty()) {
		ii u = q.front(); q.pop();
		int i = u.first, j = u.second;
		if (u == t) return dist[i][j];
		fori(k, 0, 4) {
			int ni = i + mi[k], nj = j + mj[k];
			if (ni < 0 || ni >= n || nj < 0 || nj >= m || board[ni][nj] == '#') continue;
			if (dist[ni][nj] == oo) {
				dist[ni][nj] = dist[i][j] + 1;
				q.push(ii(ni, nj));
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	while (cin >> n >> m && n) {
		memset(board, '.', sizeof board);
		int r; cin >> r;
		while (r--) {
			int id, k; cin >> id >> k;
			while (k--) {
				int x; cin >> x;
				board[id][x] = '#';
			}
		}
		ii s, t; cin >> s.first >> s.second >> t.first >> t.second;
		int ans = solver(s, t);
		cout << ans << endl;
	}
	return 0;
}