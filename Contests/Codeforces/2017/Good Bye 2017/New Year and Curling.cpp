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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	double r; cin >> r;
	vector<ii> centers(n);
	fori(i, 0, n) {
		double x, y = r; cin >> x;
		fori(j, 0, i) {
			double xp = centers[j].first, yp = centers[j].second;
			double dx = x - xp;
			if (4.0 * r * r < dx * dx) continue;
			y = max(y, yp + sqrt(4 * r * r - dx * dx));
		}
		centers[i] = ii(x, y);
	}
	fori(i, 0, n)
		cout << fixed << setprecision(8) << centers[i].second << " ";
	cout << endl;
	return 0;
}