#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9, MX = 4;

char board[MX][MX];

void doit(int c, int k) {
	fori(i, 0, MX) {
		fori(j, 0, MX) {
			if (board[i][j] == '.') {continue;}
			if (((i + j) % 2) == (c == 0 || c == 2))
				board[i][j] = c + 'A', k--;
			if (k == 0) return;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	vi v(4);
	fori(i, 0, 4)
		cin >> v[i];
	memset(board, '.', sizeof board);
	fori(c, 0, 4)
		doit(c, v[c]);
	fori(i, 0, MX) {
		fori(j, 0, MX)
			cout << board[i][j];
		cout << endl;
	}
	return 0;
}
