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

char board[mxn][mxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	memset(board, ' ', sizeof board);
	int n; cin >> n;
	fori(i, 0, n)
		board[i][0] = board[i][n - 1] = board[i][n + 1] = board[i][2 * n] = '*';
	fori(i, 0, n - 2)
		board[n - 1][i + 1] = board[0][n + 2 + i] = '*';
	fori(i, 0, n) {
		fori(j, 0, 2 * n + 1)
			cout << board[i][j];
		cout << endl;
	}
	return 0;
}