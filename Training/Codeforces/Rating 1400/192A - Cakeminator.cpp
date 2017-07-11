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

const int oo = 1e9, MAXN = 11;
char board[MAXN][MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, m; cin >> n >> m;
	fori(i, 0, n)
		fori(j, 0, m)
			cin >> board[i][j];
	int ans = 0;
	fori(i, 0, n) {
		bool flag = false;
		fori(j, 0, m) if (board[i][j] == 'S') flag = true;
		if (flag) continue;
		fori(j, 0, m) {
			ans += (board[i][j] == '.');
			board[i][j] = '*';
		}
	}
	fori(j, 0, m) {
		bool flag = false;
		fori(i, 0, n) if (board[i][j] == 'S') flag = true;
		if (flag) continue;
		fori(i, 0, n) {
			ans += (board[i][j] == '.');
			board[i][j] = '*';
		}
	}
	cout << ans << endl;
	return 0;
}