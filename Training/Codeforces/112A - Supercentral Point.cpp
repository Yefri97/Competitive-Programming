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

const int INF = 1e9;

struct point {
	int x, y;
	point() {};
	point(int _x, int _y) : x(_x), y(_y) {}
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	vector<point> points(n);
	fori(i, 0, n) {
		int x, y; cin >> x >> y;
		points[i] = point(x, y);
	}
	int ans = 0;
	fori(i, 0, n) {
		bool left = false, right = false, up = false, down = false;
		fori(j, 0, n) left  |= (points[j].x < points[i].x && points[j].y == points[i].y);
		fori(j, 0, n) right |= (points[j].x > points[i].x && points[j].y == points[i].y);
		fori(j, 0, n) up 		|= (points[j].x == points[i].x && points[j].y > points[i].y);
		fori(j, 0, n) down 	|= (points[j].x == points[i].x && points[j].y < points[i].y);
		if (left && right && up && down)
			ans++;
	}
	cout << ans << endl;
	return 0;
}