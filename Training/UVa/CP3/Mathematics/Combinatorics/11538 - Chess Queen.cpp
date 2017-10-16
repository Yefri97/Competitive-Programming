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
	ll n, m;
	while (cin >> n >> m && n) {
		if (n > m)
			swap(n, m);
		ll ans = 0;
		ans += n * m * (m - 1);
		ans += m * n * (n - 1);
		ans += (2 * (n - 1) * n * (2 * n - 1)) / 3 + 2 * (m - n) * n * (n - 1);
		cout << ans << endl;
	}
	return 0;
}