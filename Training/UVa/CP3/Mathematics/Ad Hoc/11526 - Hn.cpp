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

int bf(int n) {
	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans += n / i;
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		ll n; cin >> n;
		if (n < 0) { cout << 0 << endl; continue; }
		ll i = 2, ans = n;
		while (i * i <= n) {
			ans += n / i;
			ans += (i - 1) * (n / (i - 1) - n / i);
			i++;
		}
		for (ll j = i; j <= n / (i - 1); j++)
			ans += n / j;
		cout << ans << endl;
	}
	return 0;
}