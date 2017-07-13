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

const int oo = 1e9, MAXN = 110;
char board[MAXN][MAXN];

char hor[] = {'N', 'L', 'S', 'O'};
int mi[] = {-1, 0, 1, 0};
int mj[] = {0, 1, 0, -1};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, m, q;
	while (cin >> n >> m >> q && n) {
		int curr_hor, curr_i, curr_j;
		fori(i, 0, n) {
			fori(j, 0, m) {
				char c; cin >> c;
				if (c == 'N' || c == 'O' || c == 'S' || c == 'L') {
					fori(k, 0, 4) if (c == hor[k]) curr_hor = k;
					curr_i = i, curr_j = j;
				}
				board[i][j] = c;
			}
		}
		int ans = 0;
		fori(i, 0, q) {
			char c; cin >> c;
			if (c == 'F') {
				int ni = curr_i + mi[curr_hor], nj = curr_j + mj[curr_hor];
				if (ni >= 0 && ni < n && nj >= 0 && nj < m && board[ni][nj] != '#') {
					curr_i = ni;
					curr_j = nj;
					if (board[curr_i][curr_j] == '*')
						board[curr_i][curr_j] = '.', ans++;
				}
			} else if (c == 'D') {
				curr_hor = mod(curr_hor + 1, 4);
			} else {
				curr_hor = mod(curr_hor - 1, 4);
			}
		}
		cout << ans << endl;
	}
	return 0;
}