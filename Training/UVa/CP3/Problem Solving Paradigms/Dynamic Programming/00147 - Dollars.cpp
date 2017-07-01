// Coin Change (CC)
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

int coins[] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};

ll memo[15][30010];

ll solver(int type, int value) {
	if (value == 0) return 1;
	if (type == 11) return 0;
	if (memo[type][value] != -1) return memo[type][value];
	ll ans = 0;
	if (value >= coins[type]) ans += solver(type, value - coins[type]);
	ans += solver(type + 1, value);
	return memo[type][value] = ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	memset(memo, -1, sizeof memo);
	double d;
	while (cin >> d && d != 0.00) {
		int n = d * 100.0 + 0.5;
		ll result = solver(0, n);
		cout << fixed << setprecision(2) << setw(6) << d << setw(17) << result << endl;
	}
	return 0;
}