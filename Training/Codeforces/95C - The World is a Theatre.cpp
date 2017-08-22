#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))
#define sq(x) (x) * (x)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int oo = 1e9;

ll C(ll n, ll k) {
	ll ans = 1;
	fori(i, 0, k)
		ans = (ans * (n - i)) / (i + 1);
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, m, t; cin >> n >> m >> t;
	ll ans = 0;
	for (int b = 4; b < t; b++) {
		int g = t - b;
		ans += C(n, b) * C(m, g);
	}
	cout << ans << endl;
	return 0;
}