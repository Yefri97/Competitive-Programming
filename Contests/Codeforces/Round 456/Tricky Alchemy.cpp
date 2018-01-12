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
	ll a, b; cin >> a >> b;
	ll x, y, z; cin >> x >> y >> z;
	a -= 2 * x;
	a -= y;
	b -= y;
	b -= 3 * z;
	ll ans = 0;
	if (a < 0) ans += -a;
	if (b < 0) ans += -b;
	cout << ans << endl;
	return 0;
}