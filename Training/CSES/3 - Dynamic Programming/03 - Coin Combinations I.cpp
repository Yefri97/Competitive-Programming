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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef UTP
	freopen("input.txt", "r", stdin);
	#endif
	int n, k; cin >> n >> k;
	vi a(n);
	fori(i, 0, n) cin >> a[i];
	vi dp(k + 1);
	dp[0] = 1;
	fori(i, 1, k + 1)
		for (int x : a) if (i - x >= 0)
			dp[i] = (dp[i] + dp[i - x]) % MD;
	cout << dp[k] << endl;
	return 0;
}
