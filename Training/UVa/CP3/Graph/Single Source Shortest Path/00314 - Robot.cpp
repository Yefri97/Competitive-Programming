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

const int oo = 1e9, mxn = 60;

int n, m;
int board[mxn][mxn], dist[4][mxn][mxn];

string vs[] = {"north", "east", "south", "west"};
int mi[] = {-1, 0, 1, 0};
int mj[] = {0, 1, 0, -1};
int angle[] = {-1, 1};

struct pos {
	int i, j, hor;
	pos() {}
	pos(int _i, int _j, int _hor) : i(_i), j(_j), hor(_hor) {}
};

int bfs(pos s, pos t) {
	memset(dist, -1, sizeof dist); dist[s.hor][s.i][s.j] = 0;
	queue<pos> q; q.push(s);
	while (!q.empty()) {
		pos u = q.front(); q.pop();
		if (u.i == t.i && u.j == t.j) return dist[u.hor][u.i][u.j];
		fori(k, 1, 4) {
			pos v = pos(u.i + k * mi[u.hor], u.j + k * mj[u.hor], u.hor);
			if (v.i < 0 || v.i >= n - 1 || v.j < 0 || v.j >= m - 1) continue;
			int cnt = 0;
			fori(i, 0, 2) fori(j, 0, 2)
				cnt += board[v.i + i][v.j + j];
			if (cnt) break;
			if (dist[v.hor][v.i][v.j] == -1) {
				dist[v.hor][v.i][v.j] = dist[u.hor][u.i][u.j] + 1;
				q.push(v);
			}
		}
		fori(k, 0, 2) {
			pos v = pos(u.i, u.j, mod(u.hor + angle[k], 4));
			if (dist[v.hor][v.i][v.j] == -1) {
				dist[v.hor][v.i][v.j] = dist[u.hor][u.i][u.j] + 1;
				q.push(v);
			}
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	while (cin >> n >> m && n) {
		fori(i, 0, n)
			fori(j, 0, m)
				cin >> board[i][j];
		pos s, t; cin >> s.i >> s.j >> t.i >> t.j; s.i--; s.j--; t.i--; t.j--;
		string h; cin >> h;
		fori(i, 0, 4)
			if (vs[i] == h)
				s.hor = i;
		int ans = bfs(s, t);
		cout << ans << endl;
	}
	return 0;
}