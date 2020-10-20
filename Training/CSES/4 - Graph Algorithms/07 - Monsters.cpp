#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define SZ(X) ((int)X.size())
#define SQ(X) ((X) * (X))
#define all(X) X.begin(), X.end()
#define fori(i,a,b) for(int i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

string mov = "RULD";
int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef UTP
	freopen("input.txt", "r", stdin);
	#endif
	int n, m; cin >> n >> m;
	ii source;
	queue<ii> q;
	char board[n][m];
	vector<vi> dist_m(n, vi(m, -1));
	fori(i, 0, n) fori(j, 0, m) {
		cin >> board[i][j];
		if (board[i][j] == 'M') {
			q.push(ii(i, j));
			dist_m[i][j] = 0;
		}
		if (board[i][j] == 'A')
			source = ii(i, j);
	}
	while (!q.empty()) {
		ii u = q.front(); q.pop();
		int i = u.first, j = u.second;
		fori(k, 0, 4) {
			int ni = i + di[k];
			int nj = j + dj[k];
			if (ni < 0 || ni >= n || nj < 0 || nj >= m)
				continue;
			if (board[ni][nj] != '#' && dist_m[ni][nj] == -1) {
				dist_m[ni][nj] = dist_m[i][j] + 1;
				q.push(ii(ni, nj));
			}
		}
	}
	q.push(source);
	ii ans = ii(-1, -1);
	vector<vi> par(n, vi(m, -1));
	vector<vi> dist(n, vi(m, -1));
	par[source.first][source.second] = 5;
	dist[source.first][source.second] = 0;
	while (!q.empty()) {
		ii u = q.front(); q.pop();
		int i = u.first, j = u.second;
		if (dist_m[i][j] != -1 && dist_m[i][j] <= dist[i][j])
			continue;
		if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
			ans = u;
			break;
		}
		fori(k, 0, 4) {
			int ni = i + di[k];
			int nj = j + dj[k];
			if (board[ni][nj] != '#' && dist[ni][nj] == -1) {
				dist[ni][nj] = dist[i][j] + 1;
				par[ni][nj] = k;
				q.push(ii(ni, nj));
			}
		}
	}
	if (ans == ii(-1, -1)) {
		cout << "NO" << endl;
		return 0;
	}
	ii u = ans;
	string path;
	while (u != source) {
		int i = u.first, j = u.second;
		int k = par[i][j];
		path.push_back(mov[k]);
		int ni = i - di[k], nj = j - dj[k];
		u = ii(ni, nj);
	}
	reverse(all(path));
	cout << "YES" << endl;
	cout << SZ(path) << endl;
	cout << path << endl;
	return 0;
}
