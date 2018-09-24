#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;
const long double PI = acos(-1);

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	long double m, n, r; cin >> m >> n >> r;
	long double ax, ay, bx, by; cin >> ax >> ay >> bx >> by;
	long double tetha = PI / m, d = r / n;
	long double ans = oo;
	fori(i, 0, n + 1)
		ans = min(ans, fabs(ay - i) * d + fabs(ax - bx) * tetha * i * d + fabs(by - i) * d);
	cout << fixed << setprecision(10) << ans << endl;
	return 0;
}
