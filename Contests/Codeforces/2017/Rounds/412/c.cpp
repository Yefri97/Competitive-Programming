#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl;
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const ll INF = 1e9 + 10;

bool check(ll x, ll y, ll p, ll q, ll k) {
	return 0 <= k * p - x && k * p - x <= k * q - y;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		ll x, y, p, q; cin >> x >> y >> p >> q;
		if (q == 1) {
			if (p == 0 && x == 0 || p == 1 && x == y)
				cout << 0 << endl;
			else
				cout << -1 << endl;
			continue;
		}
		ll lo = 0, hi = INF;
		while (hi - lo > 1) {
			ll mid = (hi + lo) / 2;
			if (check(x, y, p, q, mid))
				hi = mid;
			else
				lo = mid;
		}
		cout << hi * q - y << endl;
	}
	return 0;
}