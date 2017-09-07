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

const int oo = 1e9, mxn = 110;

int r, c;
int board[mxn][mxn], memo[mxn][mxn];

int mi[] = {-1, 0, 1, 0};
int mj[] = {0, 1, 0, -1};

int solver(int i, int j) {
	if (memo[i][j] != -1) return memo[i][j];
	int ans = 0;
	fori(k, 0, 4) {
		int ni = i + mi[k], nj = j + mj[k];
		if (ni < 0 || ni >= r || nj < 0 || nj >= c) continue;
		if (board[i][j] > board[ni][nj])
			ans = max(ans, solver(ni, nj));
	}
	return memo[i][j] = ans + 1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		string name; cin >> name;
		cin >> r >> c;
		fori(i, 0, r)
			fori(j, 0, c)
				cin >> board[i][j];
		memset(memo, -1, sizeof memo);
		int ans = 0;
		fori(i, 0, r)
			fori(j, 0, c)
				ans = max(ans, solver(i, j));
		cout << name << ": " << ans << endl;
	}
	return 0;
}