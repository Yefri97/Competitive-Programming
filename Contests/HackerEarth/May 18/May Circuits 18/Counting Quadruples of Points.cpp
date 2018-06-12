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
const double EPS = 1e-8;

struct D {
	double data;
	D(double _data) : data(_data) {}
	bool operator < (const D &o) const {
		return (abs(data - o.data) > EPS && data < o.data);
	}
};

double dist(ii a, ii b) {
	int dx = a.x - b.x, dy = a.y - b.y;
	return sqrt(dx * dx + dy * dy);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);	
	int n; cin >> n;
	vector<ii> points(n);
	fori(i, 0, n)
		cin >> points[i].x >> points[i].y;
	ll ans = 0;
	fori(i, 0, n) {
		fori(j, 0, n) if (j != i) {
			map<D, int> cnt;
			fori(k, 0, n) if (k != j && k != i) {
				D c = D(dist(points[i], points[k]) - dist(points[j], points[k]));
				ans += 2 * cnt[c];
				cnt[c]++;
			}
		}
	}
	cout << ans << endl;

	return 0;
}