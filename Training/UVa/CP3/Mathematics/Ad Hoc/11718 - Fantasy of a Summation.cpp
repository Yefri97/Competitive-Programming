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

ll fastExp(ll b, ll p, ll m) {
	if (p == 0) return 1;
	if (p == 1) return b % m;
	ll ans = fastExp(b, p / 2, m);
	ans = (ans * ans) % m;
	if (p % 2 == 1) ans = (ans * b) % m;
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t, cs = 0; cin >> t;
	while (t--) {
		ll n, k, m; cin >> n >> k >> m;
		vector<ll> v(n);
		fori(i, 0, n)
			cin >> v[i];
		ll acc = 0;
		fori(i, 0, n)
			acc = (acc + v[i]) % m;
		ll ans = ((k % m) * fastExp(n, k - 1, m) * acc) % m;
		cout << "Case " << ++cs << ": " << ans << endl;
	}
	return 0;
}