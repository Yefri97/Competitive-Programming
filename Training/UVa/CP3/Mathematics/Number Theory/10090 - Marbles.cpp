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

ll x, y, d;

void extendedEuclidean(ll a, ll b) {
	if (b == 0) { d = a; x = 1; y = 0; return; }
	extendedEuclidean(b, a % b);
	ll x1 = x;
	ll y1 = y;
	x = y1;
	y = x1 - y1 * (a / b);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n;
	while (cin >> n && n) {
		ll c1, a; cin >> c1 >> a;
		ll c2, b; cin >> c2 >> b;
		extendedEuclidean(a, b);
		ii ans = ii(-1, -1);
		if (n % d == 0) {
			ll k = n / d;
			ll low = ceil(-k * x * d / (double)b), high = floor(k * y * d / (double)a);
			if (low <= high) {
				if (c1 * (b / d) * (high - low) < c2 * (a / d) * (high - low))
					ans = ii(k * x + (b / d) * high, k * y - (a / d) * high);
				else
					ans = ii(k * x + (b / d) * low, k * y - (a / d) * low);
			}
		}
		if (ans.first == -1)
			cout << "failed" << endl;
		else
			cout << ans.first << " " << ans.second << endl;
	}
	return 0;
}