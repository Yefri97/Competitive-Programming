#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

const int oo = 1e9;

long double doit(vii &v, ll t) {
	int n = v.size();
	vector<ll> x(n);
	fori(i, 0, n)
		x[i] = v[i].first * v[i].second;
	fori(i, 1, n)
		x[i] += x[i - 1];
	int p = upper_bound(x.begin(), x.end(), t) - x.begin();
	long double ans = 0.0;
	fori(i, 0, p)
		ans += v[i].second;
	if (p < n) ans += 1.0 * (t - (p > 0 ? x[p - 1] : 0)) / v[p].first;
	return ans;
}

long double solve(vii &v, ll T) {
	long double ans = 0.0;
	vii neg, pos;
	for (auto x : v) {
		if (x.first == T)
			ans += x.second;
		if (x.first < T)
			neg.push_back(ii(T - x.first, x.second));
		if (x.first > T)
			pos.push_back(ii(x.first - T, x.second));
	}
	sort(neg.begin(), neg.end());
	sort(pos.begin(), pos.end());
	int n = neg.size(), m = pos.size();
	ll a = 0, b = 0;
	fori(i, 0, n)
		a += neg[i].first * neg[i].second;
	fori(i, 0, m)
		b += pos[i].first * pos[i].second;
	ll x = min(a, b);
	ans += doit(neg, x);
	ans += doit(pos, x);
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, T; cin >> n >> T;
	vii v(n);
	fori(i, 0, n)
		cin >> v[i].second;
	fori(i, 0, n)
		cin >> v[i].first;
	long double ans = solve(v, T);
	cout << fixed << setprecision(10) << ans << endl;
	return 0;
}