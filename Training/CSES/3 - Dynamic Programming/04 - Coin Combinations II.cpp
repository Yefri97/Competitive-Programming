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
	int n, x; cin >> n >> x;
	vi a(n);
	fori(i, 0, n) cin >> a[i];
	vector<vi> dp(2, vi(x + 1));
	dp[0][0] = dp[1][0] = 1;
	fori(i, 0, n) {
		fori(j, 1, x + 1) {
			int op1 = 0, op2 = 0;
			if (j - a[i] >= 0)
				op1 = dp[i % 2][j - a[i]];
			if (i > 0)
				op2 = dp[(i + 1) % 2][j];
			dp[i % 2][j] = (op1 + op2) % MD;
		}
	}
	cout << dp[(n + 1) % 2][x] << endl;
	return 0;
}
