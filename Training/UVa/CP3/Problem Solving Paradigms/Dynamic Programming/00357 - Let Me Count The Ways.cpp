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

const int INF = 1e9, MAXN = 30010;

ll memo[10][MAXN];
int coins[] = {1, 5, 10, 25, 50};

ll solver(int type, int value) {
	if (value == 0) return 1;
	if (type == 5) return 0;
	if (memo[type][value] != -1) return memo[type][value];
	ll ans = 0;
	ans += solver(type + 1, value);
	if (coins[type] <= value) ans += solver(type, value - coins[type]);
	return memo[type][value] = ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	memset(memo, -1, sizeof memo);
	int n;
	while (cin >> n) {
		ll result = solver(0, n);
		if (result == 1) {
			cout << "There is only 1 way to produce " << n << " cents change." << endl;
		} else {
			cout << "There are " << result << " ways to produce " << n << " cents change." << endl;
		}
	}
	return 0;
}