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

const int oo = 1e9, mxn = 110;
int r, c, mv[2];
char board[mxn][mxn];
int A[mxn][mxn];

int mi[] = {1, 1, -1, -1};
int mj[] = {-1, 1, 1, -1};

void solver(int i, int j) {
	board[i][j] = '*';
	set<ii> s;
	fori(l, 0, 2) {
		fori(k, 0, 4) {
			int ni = i + mi[k] * mv[l];
			int nj = j + mj[k] * mv[1 - l];
			if (ni < 0 || ni >= r || nj < 0 || nj >= c || board[ni][nj] == '#') continue;
			s.insert(ii(ni, nj));
		}
	}
	A[i][j] = s.size() % 2;
	for (set<ii>::iterator it = s.begin(); it != s.end(); it++) {
		int ni = (*it).first, nj = (*it).second;
		if (board[ni][nj] != '*')
			solver(ni, nj);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t, cs = 0; cin >> t;
	while (t--) {
		cin >> r >> c >> mv[0] >> mv[1];
		fori(i, 0, r)
			fori(j, 0, c)
				board[i][j] = '.';
		int w; cin >> w;
		fori(i, 0, w) {
			int x, y; cin >> x >> y;
			board[x][y] = '#';
		}
		memset(A, -1, sizeof A);
		solver(0, 0);
		vi ans(2);
		fori(i, 0, r)
			fori(j, 0, c)
				if (A[i][j] != -1)
					ans[A[i][j]]++;
		cout << "Case " << ++cs << ": " << ans[0] << " " << ans[1] << endl;
	}
	return 0;
}