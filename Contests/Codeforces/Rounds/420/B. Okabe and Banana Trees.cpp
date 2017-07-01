#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int INF = 1e9;

ll gauss(ll n) { return (n * (n + 1)) / 2; }

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll m, b; cin >> m >> b;
	ll ans = 0;
	fori(y, 0, b + 1) {
		ll x = m * (b - y);
		ans = max(ans, (x + 1) * gauss(y) + (y + 1) * gauss(x));
	}
	cout << ans << endl;
	return 0;
}