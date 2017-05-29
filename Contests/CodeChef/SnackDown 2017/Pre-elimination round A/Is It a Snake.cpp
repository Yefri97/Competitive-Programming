#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl;
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int INF = 1e9, MAXN = 500;

int n;
char board[2][MAXN];

bool check(int y, int x) {
	while (true) {
		if (board[1 - y][x] == '#') y = 1 - y;
		if (x + 1 == n || board[y][x + 1] != '#') break;
		x++;
	}
	fori(i, 0, 2)
		fori(j, x + 1, n)
			if (board[i][j] == '#')
				return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> n;
		fori(i, 0, 2)
			fori(j, 0, n)
				cin >> board[i][j];
		int x = 0;
		while (board[0][x] != '#' && board[1][x] != '#') x++;
		bool ans = (board[0][x] == '#' && check(0, x)) || (board[1][x] == '#' && check(1, x));
		cout << (ans ? "yes" : "no") << endl;
	}
	return 0;
}