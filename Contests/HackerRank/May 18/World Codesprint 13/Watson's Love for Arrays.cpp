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
	int t; cin >> t;
	while (t--) {
		ll n, m, k; cin >> n >> m >> k;
		vi v(n);
		fori(i, 0, n)
			cin >> v[i];
		if (k == 0) {
			ll ans = 0, cnt = 0;
			fori(i, 0, n) {
				if (v[i] % m == 0)
					cnt = 0;
				else
					cnt++;
				ans += cnt;
			}
			cout << (n * (n + 1)) / 2 - ans << endl;
		} else {
			map<ll, ll> f;
			ll ans = 0, p = 1;
			f[(p * k) % m]++;
			fori(i, 0, n) {
				ll x = v[i] % m;
				if (x == 0) {
					f.clear();
					p = 1;
				} else {
					p = (p * x) % m;
					ans += f[p];
				}
				f[(p * k) % m]++;
			}
			cout << ans << endl;
		}
	}
	return 0;
}
