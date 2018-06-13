#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const ll oo = 1e15;
const int MN = 100010;

ll dp[MN][2][2];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<ll> v(n);
		fori(i, 0, n)
			cin >> v[i];
		fori(i, 0, n)
			dp[i][0][0] = dp[i][0][1] = dp[i][1][0] = dp[i][1][1] = oo;
		dp[n - 1][1][1] = dp[n - 1][1][0] = v[n - 1];
		dp[n - 1][0][1] = -v[n - 1];
		dp[n - 2][1][1] = v[n - 2] + v[n - 1];
		if (v[n - 2] - v[n - 1] > 0)
			dp[n - 2][1][0] = v[n - 2] - v[n - 1];
		if (v[n - 1] - v[n - 2] > 0)
			dp[n - 2][0][1] = v[n - 1] - v[n - 2];
		for (int i = n - 3; i >= 0; i--) {
			if (v[i] - v[i + 1] > 0 && v[i + 2] - v[i + 1] > 0)
				dp[i][1][0] = dp[i + 1][0][1] + v[i];
			dp[i][1][1] = min(dp[i + 1][1][1] + v[i], dp[i + 1][1][0] + v[i]);
			if (-v[i] + v[i + 1] > 0)
				dp[i][0][1] = dp[i + 1][1][1] - v[i];
			if (-v[i] + v[i + 1] - v[i + 2] > 0)
				dp[i][0][1] = min(dp[i][0][1], dp[i + 1][1][0] - v[i]);
		}
		int sign = (min(dp[0][1][1], dp[0][1][0]) < dp[0][0][1] ? 1 : -1);
		ll res = (sign == 1 ? min(dp[0][1][1], dp[0][1][0]) : dp[0][0][1]);
		fori(i, 0, n - 1) {
			cout << sign * v[i] << " ";
			int ns = sign;
			if (sign == 1) {
				if (min(dp[i + 1][1][1], dp[i + 1][1][0]) + v[i] != res) {
					ns = -1;
				}
			} else {
				ns = 1;
			}
			res -= sign * v[i];
			sign = ns;
		}
		cout << sign * v[n - 1] << endl;
	}
	return 0;
}
