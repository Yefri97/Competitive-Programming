#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	vector<ll> x(n);
	fori(i, 0, n)
		cin >> x[i];
	ll w, v; cin >> w >> v;
	int q; cin >> q;
	while (q--) {
		ll p, t, u; cin >> p >> t >> u;
		int j = upper_bound(x.begin(), x.end(), p) - x.begin();
		long double l = t + (p - x[j - 1]) * 1.0 / u - x[j - 1] * 1.0 / v;
		long double r = t + (x[j] - p) * 1.0 / u - x[j] * 1.0 / v;
		long double k = min(l, r);
		if (k < 0) k = 0.0;
		long double bus = ceil(k * 1.0 / w) * w + x[n - 1] * 1.0 / v;
		long double walk = t + (x[n - 1] - p) * 1.0 / u;
		long double ans = min(walk, bus);
		cout << fixed << setprecision(10) << ans << endl;
	}
	return 0;
}
