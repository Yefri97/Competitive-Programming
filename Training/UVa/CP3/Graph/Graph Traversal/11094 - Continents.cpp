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

const int oo = 1e9, mxn = 30;
int n, m;
char board[mxn][mxn];

int mi[] = {-1, 0, 1, 0};
int mj[] = {0, 1, 0, -1};

int flood_fill(int i, int j, char d, char c) {
	board[i][j] = d;
	int ans = 1;
	fori(k, 0, 4) {
		int ni = i + mi[k], nj = mod(j + mj[k], m);
		if (ni < 0 || ni >= n) continue;
		if (board[ni][nj] == c)
			ans += flood_fill(ni, nj, d, c);
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	while (cin >> n >> m) {
		fori(i, 0, n)
			fori(j, 0, m)
				cin >> board[i][j];
		int x, y; cin >> x >> y;
		char l = board[x][y];
		flood_fill(x, y, '#', l);
		int ans = 0;
		fori(i, 0, n)
			fori(j, 0, m)
				if (board[i][j] == l)
					ans = max(ans, flood_fill(i, j, '#', l));
		cout << ans << endl;
	}
	return 0;
}