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

ll dp[160][30];

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

ll fastExp(ll b, ll e) {
	if (e == 0) return 1;
	ll ans = fastExp(b, e / 2); ans *= ans;
	if (e % 2) ans *= b;
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	for (int i = 1; i <= 6; i++) dp[i][1] = 1;
	for (int j = 1; j < 24; j++)
		for (int i = 1; i < 150 - 6; i++)
			for (int k = 1; k <= 6; k++)
				dp[i + k][j + 1] += dp[i][j];
	int n, x;
	while (cin >> n >> x && n) {
		ll p = 0;
		for (int i = x; i <= 6 * n; i++)
			p += dp[i][n];
		ll q = fastExp(6, n);
		ll k = gcd(p, q);
		p /= k;
		q /= k;
		cout << p;
		if (q != 1)
			cout << "/" << q;
		cout << endl;
	}
	return 0;
}