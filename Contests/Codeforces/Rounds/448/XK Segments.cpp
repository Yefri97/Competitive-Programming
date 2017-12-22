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
	ll n, x, k;
	while (cin >> n >> x >> k) {
		vector<ll> v(n);
		fori(i, 0, n)
			cin >> v[i];
		sort(v.begin(), v.end());
		ll ans = 0;
		fori(i, 0, (int)v.size()) {
			ll L = (v[i] - 1) / x;
			int l1 = lower_bound(v.begin(), v.end(), (k + L) * x) - v.begin();
			int l2 = lower_bound(v.begin(), v.end(), v[i]) - v.begin();
			int l = max(l1, l2);
			int r = lower_bound(v.begin(), v.end(), (k + L + 1) * x) - v.begin();
			ans += r - l;
		}
		cout << ans << endl;
	}
	return 0;
}