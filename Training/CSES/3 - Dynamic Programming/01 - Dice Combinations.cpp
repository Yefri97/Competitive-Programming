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
	int n; cin >> n;
	vi dp(n + 1);
	dp[0] = 1;
	fori(i, 1, n + 1)
		fori(j, 1, 7) if (i - j >= 0)
			dp[i] = (dp[i] + dp[i - j]) % MD;
	cout << dp[n] << endl;
	return 0;
}
