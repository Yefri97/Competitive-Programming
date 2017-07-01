#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int INF = 1e9, MAXN = 60;
int n, board[MAXN][MAXN];

bool check(int r, int c, int k) {
	fori(i, 0, n)
		fori(j, 0, n)
			if (board[i][c] + board[r][j] == k)
				return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	fori(i, 0, n)
		fori(j, 0, n)
			cin >> board[i][j];
	bool ans = true;
	fori(i, 0, n)
		fori(j, 0, n)
			if (board[i][j] != 1)
				ans &= check(i, j, board[i][j]);
	cout << (ans ? "Yes" : "No") << endl;
	return 0;
}