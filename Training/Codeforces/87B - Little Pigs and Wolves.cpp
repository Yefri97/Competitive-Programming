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

const int oo = 1e9, mxn = 15;
char board[mxn][mxn];

int mi[] = {-1, 0, 1, 0};
int mj[] = {0, 1, 0, -1};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, m; cin >> n >> m;
	fori(i, 0, n)
		fori(j, 0, m)
			cin >> board[i][j];
	int ans = 0;
	fori(i, 0, n) {
		fori(j, 0, m) {
			if (board[i][j] == 'P') {
				fori(k, 0, 4) {
					int ni = i + mi[k], nj = j + mj[k];
					if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
					if (board[ni][nj] == 'W') {
						board[i][j] = board[ni][nj] = '.';
						ans++;
					}
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}