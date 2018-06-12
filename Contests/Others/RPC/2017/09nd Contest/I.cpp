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
	ll m, k;
	while (cin >> m >> k) {
		ll ans = (1LL << 51), x = (1LL << k) - 1, xx = 0;
		while (x < (1LL << 51)) {
			if ((m | x) == m) { ans = m; break; }
			ans = min(ans, (m | x) & ~xx);
			x <<= 1;
			xx = (xx << 1) | 1;
		}
		cout << ans << endl;
	}
	return 0;
}