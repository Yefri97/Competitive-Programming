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

const int oo = 1e9;

struct Pos {
	int x, y, hor;
	Pos() {}
	Pos(int _x, int _y, int _hor) : x(_x), y(_y), hor(_hor) {}
};

int n, m, fall;
int scent[100][100];
char vh[] = {'N', 'E', 'S', 'W'};
int mx[] = {0, 1, 0, -1};
int my[] = {1, 0, -1, 0};

Pos solver(Pos robot, string cmd) {
	fori(i, 0, cmd.size()) {
		char ch = cmd[i];
		if (ch == 'F') {
			int nx = robot.x + mx[robot.hor];
			int ny = robot.y + my[robot.hor];
			if (nx < 0 || nx > n || ny < 0 || ny > m) {
				if (!scent[robot.x][robot.y]) {
					scent[robot.x][robot.y] = 1;
					fall = 1;
					break;
				}
			} else {
				robot.x = nx;
				robot.y = ny;
			}
		} else if (ch == 'L') {
			robot.hor = mod(robot.hor - 1, 4);
		} else {
			robot.hor = mod(robot.hor + 1, 4);
		}
	}
	return robot;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	Pos robot;
	while (cin >> robot.x) {
		char h;
		cin >> robot.y >> h;
		fori(i, 0, 4) if (h == vh[i]) robot.hor = i;
		string cmd; cin >> cmd;
		fall = 0;
		Pos ans = solver(robot, cmd);
		cout << ans.x << " " << ans.y << " " << vh[ans.hor];
		if (fall) cout << " LOST";
		cout << endl;
	}
	return 0;
}