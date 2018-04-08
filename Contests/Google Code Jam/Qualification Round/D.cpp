#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;
const double PI = acos(-1);

struct PT {
	double x, y, z;
	PT() {}
	PT(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {}
};

PT rotateX(PT p, double angle) { return PT(p.x, p.y * cos(angle) + p.z * sin(angle), -p.y * sin(angle) + p.z * cos(angle)); }
PT rotateY(PT p, double angle) { return PT(p.x * cos(angle) - p.z * sin(angle), p.y, p.x * sin(angle) + p.z * cos(angle)); }
PT rotateZ(PT p, double angle) { return PT(p.x * cos(angle) + p.y * sin(angle), -p.x * sin(angle) + p.y * cos(angle), p.z); }

double dist(PT a, PT b) {
	double dx = a.x - b.x;
	double dy = a.y - b.y;
	return sqrt(dx * dx + dy * dy);
}

double cross(PT p, PT q) { return p.x * q.y - p.y * q.x; }

double area(vector<PT> &pol) {
	double ans = 0.0;
	fori(i, 1, pol.size() - 1) {
		PT p = pol[i], q = pol[i + 1], o = pol[0];
		p.x -= o.x, p.y -= o.y;
		q.x -= o.x, q.y -= o.y;
		ans += cross(p, q);
	}
	return ans * -0.5;
}

bool check(vector<PT> pol, double A, double angle) {
	fori(i, 0, 6) pol[i] = rotateY(pol[i], angle);
	return area(pol) > A;
}

void debugPT(PT p) { cout << p.x << " " << p.y << " " << p.z << endl; }

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int tc; cin >> tc;
	fori(t, 0, tc) {

		vector<PT> ans(3);
		ans[0] = PT(0.5, 0, 0);
		ans[1] = PT(0, 0.5, 0);
		ans[2] = PT(0, 0, 0.5);

		double A; cin >> A;

		vector<PT> pol;

		if (A > sqrt(2)) {

			pol.push_back(PT(-0.5, -0.5, -0.5));
			pol.push_back(PT(-0.5, -0.5,  0.5));
			pol.push_back(PT(-0.5,  0.5,  0.5));
			pol.push_back(PT( 0.5,  0.5,  0.5));
			pol.push_back(PT( 0.5,  0.5, -0.5));
			pol.push_back(PT( 0.5, -0.5, -0.5));

			fori(i, 0, 6) pol[i] = rotateX(pol[i], PI * 0.25);
			fori(i, 0, 3) ans[i] = rotateX(ans[i], PI * 0.25);

		} else {

			pol.push_back(PT(-0.5, -0.5,  0.5));
			pol.push_back(PT(-0.5,  0.5,  0.5));
			pol.push_back(PT( 0.5,  0.5, -0.5));
			pol.push_back(PT( 0.5, -0.5, -0.5));

		}

		double lo = 0.0, hi = PI * 0.25;
		fori(i, 0, 60) {
			double md = (lo + hi) * 0.5;
			if (check(pol, A, md)) {
				hi = md;
			} else {
				lo = md;
			}
		}

		fori(i, 0, 6) pol[i] = rotateY(pol[i], hi);
		debug(area(pol));

		fori(i, 0, 3)
			ans[i] = rotateY(ans[i], hi);

		cout << "Case #" << t + 1 << ":" << endl;
		fori(i, 0, 3)
			cout << ans[i].x << " " << ans[i].y << " " << ans[i].z << endl;

	}
	return 0;
}