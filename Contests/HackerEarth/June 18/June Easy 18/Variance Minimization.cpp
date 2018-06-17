#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const ll oo = 1e18;

ll solve(vector<ll> &a, ll total, ll total2, int id) {
	int n = a.size();
	ll s = total - a[id];
	ll ss = total2 - a[id] * a[id];
	ll p1 = s / (n - 1), p2 = (s + n - 2) / (n - 1);
	ll ans = oo;
	ans = min(ans, n * (ss + p1 * p1) - (s + p1) * (s + p1));
	ans = min(ans, n * (ss + p2 * p2) - (s + p2) * (s + p2));
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<ll> x(n), y(n);
		ll sx = 0, ssx = 0;
		ll sy = 0, ssy = 0;
		fori(i, 0, n) {
			cin >> x[i] >> y[i];
			sx += x[i];
			sy += y[i];
			ssx += (x[i] * x[i]);
			ssy += (y[i] * y[i]);
		}
		ll ans = oo;
		fori(i, 0, n)
			ans = min(ans, solve(x, sx, ssx, i) +  solve(y, sy, ssy, i));
		cout << ans << endl;
	}
	return 0;
}