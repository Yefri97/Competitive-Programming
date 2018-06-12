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
	ll n, k; cin >> n >> k;
	vector<ll> v(n + 1);
	fori(i, 1, n + 1) cin >> v[i];
	fori(i, 1, n + 1) v[i] += v[i - 1];
	ll cnt = 0, ans = 0;
	fori(i, 1, n + 1) {
		ll l = lower_bound(v.begin(), v.end(), k + v[i - 1]) - v.begin();
		ll r = upper_bound(v.begin(), v.end(), k + v[i - 1]) - v.begin();
		cnt += r - l;
		if (r != l) ans = max(ans, r - i);
	}
	cout << cnt << " " << n - ans << endl;
	return 0;
}