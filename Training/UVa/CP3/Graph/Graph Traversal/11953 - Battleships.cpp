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

int n;
char board[mxn][mxn];
int mi[] = {-1, 0, 1, 0};
int mj[] = {0, 1, 0, -1};

void flood_fill(int i, int j, char d, char c) {
	board[i][j] = d;
	fori(k, 0, 4) {
		int ni = i + mi[k], nj = j + mj[k];
		if (ni < 0 || ni >= n || nj < 0 || nj >= n) continue;
		if (board[ni][nj] == c || board[ni][nj] == '@')
			flood_fill(ni, nj, d, c);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t, cs = 0; cin >> t;
	while (t--) {
		cin >> n;
		fori(i, 0, n)
			fori(j, 0, n)
				cin >> board[i][j];
		int ans = 0;
		fori(i, 0, n) {
			fori(j, 0, n) {
				if (board[i][j] == 'x') {
					flood_fill(i, j, '#', 'x');
					ans++;
				}
			}
		}
		cout << "Case " << ++cs << ": " << ans << endl;
	}
	return 0;
}