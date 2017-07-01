// Binomial Codefficientes
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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n, k;
	while (cin >> n >> k && (n || k)) {
		k = min(k, n - k);
		ll ans = 1;
		fori(i, 0, k) {
			ans *= (n - i);
			ans /= (i + 1);
		}
		cout << ans << endl;
	}
	return 0;
}