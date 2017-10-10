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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	/*
	int board[20][20];
	fori(i, 0, 10) {
		fori(j, 0, 10)
			cout << setw(3) << ((i + 1) * (j + 1)) / 2;
		cout << endl;
	}
	fori(i, 0, 10) {
		fori(j, 0, 10) {
			if (i > 0) board[i][j] += board[i - 1][j];
			if (j > 0) board[i][j] += board[i][j - 1];
			if (i > 0 && j > 0) board[i][j] -= board[i - 1][j - 1];
		}
	}
	fori(i, 0, 10) {
		fori(j, 0, 10)
			cout << setw(3) << board[i][j];
		cout << endl;
	}
	*/
	int n, m, c;
	while (cin >> n >> m >> c && n) {
		n -= 7; m -= 7;
		if (((n + m) % 2) != c)
			cout << ((n * m) + 1) / 2 << endl;
		else
			cout << (n * m) / 2 << endl;
	}
	return 0;
}