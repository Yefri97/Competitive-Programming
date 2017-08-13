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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t, cs = 0; cin >> t;
	while (t--) {
		int c, d; cin >> c >> d;
		double f = (9.0 / 5) * c + 32;
		f += d;
		double ans = (f - 32) * (5 / 9.0);
		cout << "Case " << ++cs << ": ";
		cout << fixed << setprecision(2) << ans << endl;
	}
	return 0;
}