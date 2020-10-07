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

int n, m;
int vis[MN][MN];
char board[MN][MN];
int di[] = {-1, 0, 1, 0};
int dj[] = {0, 1, 0, -1};

void dfs(int i, int j) {
	vis[i][j] = 1;
	fori(k, 0, 4) {
		int ni = i + di[k], nj = j + dj[k];
		if (ni < 0 || nj < 0 || ni >= n || nj >= m) continue;
		if (board[ni][nj] == '.' && !vis[ni][nj])
			dfs(ni, nj);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef UTP
	freopen("input.txt", "r", stdin);
	#endif
	cin >> n >> m;
	fori(i, 0, n) fori(j, 0, m)
		cin >> board[i][j];
	int ans = 0;
	fori(i, 0, n) fori(j, 0, m) {
		if (board[i][j] == '.' && !vis[i][j]) {
			dfs(i, j);
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
