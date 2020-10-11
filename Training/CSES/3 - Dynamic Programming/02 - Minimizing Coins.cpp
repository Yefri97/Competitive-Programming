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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef UTP
	freopen("input.txt", "r", stdin);
	#endif
	int n, x; cin >> n >> x;
	vi a(n), dp(x + 1, oo);
	fori(i, 0, n) cin >> a[i];
	dp[0] = 0;
	fori(i, 1, x + 1) {
		fori(j, 0, n) if (i - a[j] >= 0)
			dp[i] = min(dp[i], dp[i - a[j]] + 1);
	}
	cout << (dp[x] < oo ? dp[x] : -1) << endl;
	return 0;
}
