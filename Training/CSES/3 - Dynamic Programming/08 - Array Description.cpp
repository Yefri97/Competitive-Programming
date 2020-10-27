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
	int n, m; cin >> n >> m;
	vi a(n);
	for (int &x : a) cin >> x;
	int l, r;
	l = 1; r = m;
	vector<vi> dp(2, vi(m + 1));
	if (a[0] != 0) l = r = a[0];
	fori(i, l, r + 1) dp[0][i] = 1;
	fori(i, 1, n) {
		fori(j, 1, m + 1) dp[i % 2][j] = 0;
		l = 1; r = m;
		if (a[i] != 0) l = r = a[i];
		fori(j, l, r + 1) {
			fori(k, -1, 2) {
				if (1 <= j + k && j + k <= m) {
					int x = dp[(i + 1) % 2][j + k];
					dp[i % 2][j] = (dp[i % 2][j] + x) % MD;
				}
			}
		}
	}
	l = 1; r = m;
	if (a[n - 1] != 0) l = r = a[n - 1];
	int ans = 0;
	fori(i, l, r + 1)
		ans = (ans + dp[(n + 1) % 2][i]) % MD;
	cout << ans << endl;
	return 0;
}
