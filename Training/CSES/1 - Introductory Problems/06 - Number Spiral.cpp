#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define SZ(X) ((int)X.size())
#define SQ(X) ((X) * (X))
#define all(X) X.begin(), X.end()
#define fori(i,a,b) for(int i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef UTP
	freopen("input.txt", "r", stdin);
	#endif
	int t; cin >> t;
	while (t--) {
		ll y, x; cin >> y >> x;
		ll ans;
		if (y > x) {
			if (y % 2) {
				ans = (y - 1) * (y - 1) + x;
			} else {
				ans = y * y + 1 - x;
			}
		} else {
			if (x % 2) {
				ans = x * x + 1 - y;
			} else {
				ans = (x - 1) * (x - 1) + y;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
