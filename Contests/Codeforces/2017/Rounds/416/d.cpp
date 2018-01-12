#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int INF = 1e9, MAXN = 110;
char board[MAXN][MAXN];

int n, m;
vector<char> path;

char cmd[] = {'L', 'U', 'R', 'D'};
int mi[] = {0, -1, 0, 1};
int mj[] = {-1, 0, 1, 0};

bool dfs(int i, int j) {
	if (board[i][j] == 'F') return true;
	board[i][j] = '*';
	fori(k, 0, 4) {
		int ni = i + mi[k], nj = j + mj[k];
		if (ni < 0 || ni >= n || nj < 0 || nj >= m || board[ni][nj] == '*') continue;
		path.push_back(cmd[k]);
		if (dfs(ni, nj)) return true;
		path.pop_back();
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	fori(i, 0, n)
		fori(j, 0, m)
			cin >> board[i][j];
	dfs(0, 0);
	int i = 1, j = 1, broken_hor = -1, broken_ver = -1;
	fori(k, 0, path.size()) {
		char stp = path[k];
		if (stp == 'L' || stp == 'R') {
			if (broken_hor == -1) {
				cout << "R" << endl << flush;
				int ni, nj; cin >> ni >> nj;
				if (nj == j) {
					broken_hor = 1;
					k--;
				} else {
					broken_hor = 0;
				}
				i = ni, j = nj;
				continue;
			} else {
				if (broken_hor)
					cout << ((stp == 'L') ? "R" : "L") << endl << flush;
				else
					cout << stp << endl << flush;
			}
		} else {
			if (broken_ver == -1) {
				cout << "D" << endl << flush;
				int ni, nj; cin >> ni >> nj;
				if (ni == i) {
					broken_ver = 1;
					k--;
				} else {
					broken_ver = 0;
				}
				i = ni, j = nj;
				continue;
			} else {
				if (broken_ver)
					cout << ((stp == 'U') ? "D" : "U") << endl << flush;
				else
					cout << stp << endl << flush;
			}
		}
		cin >> i >> j;
	}
	return 0;
}