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

const int oo = 1e9, mxn = 110;

int n, m;
int mx[] = {-1, 0, 1, 0};
int my[] = {0, 1, 0, -1};

char board[mxn][mxn], diagram[10][mxn][mxn];

int getDir(int x, int y, int currDir) {
	fori(i, 0, 2) {
		int nxtDir = mod(currDir + 2 * i + 1, 4);
		int nx = x + mx[nxtDir], ny = y + my[nxtDir];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
		if (board[nx][ny] == 'X')
			return nxtDir;
	}
	return -1;
}

int flood_fill(int x, int y, char c1, char c2, int id) {
	diagram[id][x][y] = c1;
	int ans = 0;
	fori(i, 0, 4) {
		int nx = x + mx[i], ny = y + my[i];
		if (diagram[id][nx][ny] == c2)
			ans += flood_fill(x + mx[i], y + my[i], c1, c2, id);
	}
	return ans + 1;
}

int getSz(int id) {
	fori(i, 0, n)
		fori(j, 0, m)
			if (diagram[id][i][j] == '#')
				return flood_fill(i + 1, j + 1, '*', '.', id);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	vvi pos(2, vi(2));
	fori(i, 0, n) {
		fori(j, 0, m) {
			char c; cin >> c;
			if (c == 'A') pos[0][0] = i, pos[0][1] = j;
			if (c == 'B') pos[1][0] = i, pos[1][1] = j;
			if (c == 'A' || c == 'B') c = 'X';
			board[i][j] = c;
		}
	}
	fori(id, 0, 2) {
		memset(diagram[id], '.', sizeof diagram[id]);
		int x = pos[id][0], y = pos[id][1], dir = getDir(x, y, 0);
		if (dir == -1) dir = getDir(x, y, 1);
		while (diagram[id][x][y] != '#') {
			diagram[id][x][y] = '#';
			int nx = x + mx[dir], ny = y + my[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m || board[nx][ny] == '.') {
				dir = getDir(x, y, dir);
				nx = x + mx[dir];
				ny = y + my[dir];
			}
			x = nx;
			y = ny;
		}
	}
	vi sz(2);
	fori(id, 0, 2)
		sz[id] = getSz(id);
	fori(id, 0, 2)
		fori(i, 0, n)
			fori(j, 0, m)
				sz[id] -= (diagram[id][i][j] == '*' && diagram[1 - id][i][j] == '#');
	int intersect = 0;
	fori(i, 0, n)
		fori(j, 0, m)
			intersect += (diagram[0][i][j] == '*' && diagram[1][i][j] == '*');
	cout << sz[0] - intersect << " " << sz[1] - intersect << " " << intersect << endl;
	return 0;
}