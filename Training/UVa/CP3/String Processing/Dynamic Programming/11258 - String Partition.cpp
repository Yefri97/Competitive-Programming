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

const int oo = 1e9, MX = 210;

int n;
ll memo[MX];
string num;

ll dp(int id) {
	if (id == n) return 0;
	if (memo[id] != -1) return memo[id];
	if (num[id] == '0') return dp(id + 1);
	ll ans = 0;
	for (ll i = id + 1, x = num[id] - '0'; i <= n && x < (1LL << 31) - 1; x = 10 * x + num[i] - '0', i++)
		ans = max(ans, x + dp(i));
	return memo[id] = ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> num;
		n = num.size();
		memset(memo, -1, sizeof memo);
		ll ans = dp(0);
		cout << ans << endl;
	}
	return 0;
}