#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9, MD = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		ll total1 = 0, total2 = 0;
		fori(i, 0, n) {
			int num; cin >> num;
			total1 = (total1 + num) % MD;
		}
		fori(i, 0, n) {
			int num; cin >> num;
			total2 = (total2 + num) % MD;
		}
		vector<ll> x(m), y(m);
		x[0] = 1; y[1] = 1;
		fori(i, 2, m) {
			x[i] = (x[i - 1] + x[i - 2]) % MD;
			y[i] = (y[i - 1] + y[i - 2]) % MD;
		}
		ll c1 = (total1 * x[m - 1]) % MD;
		ll c2 = (total2 * y[m - 1]) % MD;
		ll ans = (n * ((c1 + c2) % MD)) % MD;
		cout << ans << endl;
	}
	return 0;
}
