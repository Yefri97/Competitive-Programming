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

const int oo = 1e9, n = 9;

char board[n][n];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	fori(i, 0, n)
		fori(j, 0, n)
			cin >> board[i][j];
	int x, y; cin >> x >> y; x--; y--;
	x = (x % 3) * 3; y = (y % 3) * 3;
	bool flag = false;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[x + i][y + j] == '.') {
				board[x + i][y + j] = '!';
				flag = true;
			}
		}
	}
	if (!flag) {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (board[i][j] == '.')
					board[i][j] = '!';
	}
	for (int i = 0; i < n; i++) {
		if (i != 0 && i % 3 == 0) cout << endl;
		for (int j = 0; j < n; j++) {
			if (j != 0 && j % 3 == 0) cout << " ";
			cout << board[i][j];
		}
		cout << endl;
	}
	return 0;
}