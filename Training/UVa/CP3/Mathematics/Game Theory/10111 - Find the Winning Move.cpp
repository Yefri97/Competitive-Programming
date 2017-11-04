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

const int oo = 1e9;

char board[5][5];

bool check(int id) {
	char c = (id == 0 ? 'x' : 'o');
	fori(i, 0, 4) {
		bool x = true, y = true;
		fori(j, 0, 4) {
			x &= (board[i][j] == c);
			y &= (board[j][i] == c);
		}
		if (x || y) return true;
	}
	bool x = true, y = true;
	fori(i, 0, 4) {
		x &= (board[i][i] == c);
		y &= (board[i][3 - i] == c);
	}
	if (x || y) return true;
	return false;
}

bool go(int id) {
	if (check(1 - id)) return false;
	bool m = false;
	fori(i, 0, 4)
		fori(j, 0, 4)
			m |= (board[i][j] == '.');
	if (!m) return id;
	fori(i, 0, 4) {
		fori(j, 0, 4) if (board[i][j] == '.') {
			board[i][j] = (id == 0 ? 'x' : 'o');
			bool w = go(1 - id);
			board[i][j] = '.';
			if (!w) return true;
		}
	}
	return false;
}

ii solver() {
	fori(i, 0, 4) {
		fori(j, 0, 4) if (board[i][j] == '.') {
			board[i][j] = 'x';
			if (!go(1))
				return ii(i, j);
			board[i][j] = '.';
		}
	}
	return ii(-1, -1);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	char c;
	while (cin >> c && c != '$') {
		fori(i, 0, 4)
			fori(j, 0, 4)
				cin >> board[i][j];
		ii ans = solver();
		if (ans.first != -1)
			cout << "(" << ans.first << "," << ans.second << ")" << endl;
		else
			cout << "#####" << endl;
	}
	return 0;
}