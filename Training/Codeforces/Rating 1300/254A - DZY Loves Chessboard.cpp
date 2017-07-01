#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int INF = 1e9, MAXN = 110;

int n, m;
char board[MAXN][MAXN];

int mi[] = {0, -1, 0, 1};
int mj[] = {-1, 0, 1, 0};

void dfs(int i, int j, char c) {
	board[i][j] = c;
	fori(k, 0, 4) {
		int ni = i + mi[k], nj = j + mj[k];
		if (ni < 0 || ni >= n || nj < 0 || nj >= m || board[ni][nj] == '-') continue;
		if (board[ni][nj] == '.')
			dfs(ni, nj, (c == 'B' ? 'W' : 'B'));
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	fori(i, 0, n)
		fori(j, 0, m)
			cin >> board[i][j];
	fori(i, 0, n)
		fori(j, 0, m)
			if (board[i][j] == '.')
				dfs(i, j, 'B');
	fori(i, 0, n) {
		fori(j, 0, m)
			cout << board[i][j];
		cout << endl;
	}
	return 0;
}