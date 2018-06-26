#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

int check(vector<ii> sq1, vector<ii> sq2) {
	int x1 = oo, x2 = -oo, y1 = oo, y2 = -oo;
	fori(i, 0, 4) {
		x1 = min(x1, sq2[i].x);
		x2 = max(x2, sq2[i].x);
		y1 = min(y1, sq2[i].y);
		y2 = max(y2, sq2[i].y);
	}
	for (ii p : sq1) {
		if (x1 <= p.x && p.x <= x2 && y1 <= p.y && p.y <= y2)
			return true;
	}
	int xp1 = oo, xp2 = -oo, yp1 = oo, yp2 = -oo;
	fori(i, 0, 4) {
		xp1 = min(xp1, sq1[i].x);
		xp2 = max(xp2, sq1[i].x);
		yp1 = min(yp1, sq1[i].y);
		yp2 = max(yp2, sq1[i].y);
	}
	int dx = xp1 + xp2;
	int dy = yp1 + yp2;
	return 2 * x1 <= dx && dx <= 2 * x2 && 2 * y1 <= dy && dy <= 2 * y2;
}

int solve(vector<ii> sq1, vector<ii> sq2) {
	fori(i, 0, 4) if (check(sq2, sq1))
		return 1;
	fori(i, 0, 4)
		sq1[i] = ii(sq1[i].x - sq1[i].y, sq1[i].x + sq1[i].y);
	fori(i, 0, 4)
		sq2[i] = ii(sq2[i].x - sq2[i].y, sq2[i].x + sq2[i].y);
	fori(i, 0, 4) if (check(sq1, sq2))
		return 1;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	vector<ii> sq1(4), sq2(4);
	fori(i, 0, 4)
		cin >> sq1[i].x >> sq1[i].y;
	fori(i, 0, 4)
		cin >> sq2[i].x >> sq2[i].y;
	int ans = solve(sq1, sq2);
	cout << (ans ? "YES" : "NO") << endl;
	return 0;
}
