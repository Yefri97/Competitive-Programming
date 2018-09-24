#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define SZ(v) (int)v.size()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

void extendedEuclidean(ll a, ll b, ll &d, ll &x, ll &y) {
	if (b == 0) {
		d = a;
		x = 1;
		y = 0;
	} else {
		extendedEuclidean(b, a % b, d, x, y);
		ll x1 = x, y1 = y;
		x = y1;
		y = x1 - (a / b) * y1;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll p, q, n;
	while (cin >> p >> q >> n) {
		if (q == 1) {
			if (p == 0) {
				cout << "M(1/1)";
				fori(i, 1, n)
					cout << " M(1/" << i + 1 << ")";
				cout << endl;
			} else {
				cout << "M(0/1)";
				fori(i, 1, n)
					cout << " M(" << i << "/" << i + 1 << ")";
				cout << endl;
			}
		} else {
			ll d, x1, y1;
			extendedEuclidean(p, -q, d, x1, y1);
			vector<ii> ans(2 * n);
			fori(i, 0, n)
				ans[i] = ii(x1 + i * q, y1 + i * p);
			int c = max((y1 + p - 1) / p, (x1 + q - 1) / q);
			fori(i, 0, n)
				ans[n + i] = ii(-x1 + (c + i) * q, -y1 + (c + i) * p);
			sort(ans.begin(), ans.end());
			cout << "M(" << ans[0].second << "/" << ans[0].first << ")";
			fori(i, 1, n)
				cout << " M(" << ans[i].second << "/" << ans[i].first << ")";
			cout << endl;
		}
	}
	return 0;
}
