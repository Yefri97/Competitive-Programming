#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define SZ(X) ((int)X.size())
#define SQ(X) ((X) * (X))
#define all(X) X.begin(), X.end()
#define fori(i,a,b) for(int i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;
const int MD = 1e9 + 7;

ll gauss(ll n) { return (n * (n + 1)) / 2; }

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef UTP
	freopen("input.txt", "r", stdin);
	#endif
	ll n; cin >> n;
	ll ans = 0, last = 0;
	for (ll i = 1; i * i <= n; i++) {
		ans = (ans + i * (n / i)) % MD;
		last = n / i;
	}
	for (ll i = 1; i < last; i++) {
		ll a = gauss((n / i) % MD) % MD;
		ll b = gauss((n / (i + 1)) % MD) % MD;
		ll d = (a - b + MD) % MD;
		ans = (ans + i * d) % MD;
	}
	cout << ans << endl;
	return 0;
}
