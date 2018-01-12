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

const int oo = 1e9, MX = 60;

int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};

int n, m;
char board[MX][MX];
string cmd;
ii pos_start, pos_end;

int check(vector<int> &p) {
	int x = pos_start.first, y = pos_start.second;
	for (char c : cmd) {
		int nx = x + dx[p[c - '0']], ny = y + dy[p[c - '0']];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m || board[nx][ny] == '#') return 0;
		if (nx == pos_end.first && ny == pos_end.second) return 1;
		x = nx;
		y = ny;
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	fori(i, 0, n) {
		fori(j, 0, m) {
			char c; cin >> c;
			if (c == 'S') pos_start = ii(i, j);
			if (c == 'E') pos_end = ii(i, j);
			board[i][j] = c;
		}
	}
	cin >> cmd;
	vector<int> p(4);
	fori(i, 0, 4) p[i] = i;
	int ans = 0;
	do {
		ans += check(p);
	} while (next_permutation(p.begin(), p.end()));
	cout << ans << endl;
	return 0;
}