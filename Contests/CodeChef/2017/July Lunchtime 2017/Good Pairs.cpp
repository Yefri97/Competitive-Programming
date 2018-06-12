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

const int oo = 1e9, mxn = 1000000, k = 20, maxk = 1 << k;

ll cnt[maxk], dp[maxk];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		memset(cnt, 0, sizeof cnt);
		int n; cin >> n;
		fori(i, 0, n) {
			int x; cin >> x;
			cnt[x]++;
		}
		fori(i, 0, maxk) dp[i] = cnt[i];
		fori(j, 0, k+1)
			fori(i, 0, maxk)
				if (i & (1 << j))
					dp[i] += dp[i ^ (1 << j)];
		ll ans = 0;
		fori(i, 0, maxk)
			ans += cnt[i] * (dp[i] - cnt[i]) + ((cnt[i] * (cnt[i] - 1)) / 2);
		cout << ans << endl;
	}
	return 0;
}