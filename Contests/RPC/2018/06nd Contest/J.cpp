#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9, MN = 510, MD = 1e9 + 7;

ll f[MN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		ll c, v, l, k; cin >> c >> v >> l >> k;
		int ok = 0;
		f[0] = 1;
		f[1] = v;
		fori(i, 2, l + 1) {
			ll x = v * f[i - 1] + c * v * f[i - 2];
			if (x >= k) ok = 1;
			f[i] = x % MD;
		}
		cout << f[l] << " " << (ok ? "Accepted" : "Rejected") << endl;
	}
	return 0;
}
