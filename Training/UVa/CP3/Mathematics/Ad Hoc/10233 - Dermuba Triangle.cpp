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
typedef pair<double, double> ii;
typedef vector<ii> vii;

const int oo = 1e9;

ii getXY(int n) {
	int y = sqrt(n), x = n - y - y * y;
	return ii((double)x * 0.5, (double)y * (sqrt(3.0) / 2.0) - ((y & 1) ^ (n & 1)) * (sqrt(3) / 6.0));
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, m;
	while (cin >> n >> m) {
		ii pt1 = getXY(n);
		ii pt2 = getXY(m);
		double dx = pt1.first - pt2.first, dy = pt1.second - pt2.second;
		cout << fixed << setprecision(3) << sqrt(dx * dx + dy * dy) << endl;
	}
	return 0;
}