#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

int dp[60][60];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, m; cin >> n >> m;
	vector<ll> v(n);
	fori(i, 0, n)
		cin >> v[i];
	ll ans = 0;
	for (int bit = 60; bit >= 0; bit--) {
		ll curr = ans | (1LL << bit), s = 0;
		memset(dp, 0, sizeof dp);
		for (ll i = n - 1; i >= 0; i--) {
			s += v[i];
			dp[1][i] = ((s & curr) == curr);
		}
		for (int k = 2; k <= m; k++) {
			for (int i = n - 1; i >= 0; i--) {
				s = 0;
				for (int j = i; j < n - 1; j++) {
					s += v[j];
					dp[k][i] |= ((s & curr) == curr) & dp[k - 1][j + 1];
				}
			}
		}
		if (dp[m][0])
			ans |= (1LL << bit);
	}
	cout << ans << endl;
	return 0;
}
