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

const int oo = 1e9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int g1, p1, g2, p2; cin >> g1 >> p1 >> g2 >> p2;
	int lo, hi;
	// Find mmin
	lo = -1, hi = g1;
	while (hi - lo > 1) {
		int mid = (hi + lo) * 0.5;
		if ((mid * 100) / g1 >= p1)
			hi = mid;
		else
			lo = mid;
	}
	int mmin = hi;
	// Find mmax
	lo = 0, hi = g2 + 1;
	while (hi - lo > 1) {
		int mid = (hi + lo) * 0.5;
		if ((mid * 100) / g2 <= p2)
			lo = mid;
		else
			hi = mid;
	}
	int mmax = lo;
	cout << mmax - mmin << endl;
	return 0;
}