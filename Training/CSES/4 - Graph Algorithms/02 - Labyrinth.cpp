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
const int MN = 1010;

char board[MN][MN];
string movs = "ULDR";
int di[] = {-1, 0, 1, 0};
int dj[] = {0, -1, 0, 1};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef UTP
	freopen("input.txt", "r", stdin);
	#endif
	int n, m; cin >> n >> m;
	ii source, target;
	fori(i, 0, n) fori(j, 0, m) {
		cin >> board[i][j];
		if (board[i][j] == 'A')
			source = ii(i, j);
		if (board[i][j] == 'B') {
			target = ii(i, j);
			board[i][j] = '.';
		}
	}
	queue<ii> q; q.push(source);
	vector<vi> par(n, vi(m, -1));
	par[source.first][source.second] = 5;
	while (!q.empty()) {
		ii u = q.front(); q.pop();
		int i = u.first, j = u.second;
		fori(k, 0, 4) {
			int ni = i + di[k], nj = j + dj[k];
			if (ni < 0 || nj < 0 || ni >= n || nj >= m)
				continue;
			if (board[ni][nj] == '.' && par[ni][nj] == -1) {
				par[ni][nj] = k;
				q.push(ii(ni, nj));
			}
		}
	}
	if (par[target.first][target.second] == -1) {
		cout << "NO" << endl;
		return 0;
	}
	string ans;
	ii u = target;
	while (u != source) {
		int k = par[u.first][u.second];
		ans.push_back(movs[k]);
		int ni = u.first - di[k], nj = u.second - dj[k];
		u = ii(ni, nj);
	}
	reverse(all(ans));
	cout << "YES" << endl;
	cout << SZ(ans) << endl;
	cout << ans << endl;
	return 0;
}
