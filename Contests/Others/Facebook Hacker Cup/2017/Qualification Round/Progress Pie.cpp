// Geometry
#include <bits/stdc++.h>
using namespace std;

struct point {
	double x, y;
	point() { x = y = 0.0; }
	point(double _x, double _y) : x(_x), y(_y) {}
};

double LIMIT = 50.0, PI = 2 * acos(0.0);
point CENTER = point(50.0, 50.0), TOP = point(50.0, 100.0);

double dist(point a, point b) {
	return hypot(a.x - b.x, a.y - b.y);
}

struct vec {
	double x, y;
	vec(double _x, double _y) : x(_x), y(_y) {}
};

vec toVec(point a, point b) {
	return vec(b.x - a.x, b.y - a.y);
}

double dot(vec a, vec b) {
	return (a.x * b.x + a.y * b.y);
}

double norm_sq(vec v) {
	return (v.x * v.x + v.y * v.y);
}

double angle(point a, point o, point b) {
	vec oa = toVec(o, a), ob = toVec(o, b);
	return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
}

double RAD_to_DED(double r) { return r * 180.0 / PI; }

int main() {
	int t, cs = 1; cin >> t;
	while (t--) {
		double p, x, y; cin >> p >> x >> y;
		point q = point(x, y);
		bool ans = (dist(CENTER, q) <= LIMIT && RAD_to_DED(angle(TOP, CENTER, q)) < p * 360.0 / 100.0);
		cout << "Case #" << cs++ << ": " << ((ans)? "black" : "white") << endl;
	}
	return 0;
}