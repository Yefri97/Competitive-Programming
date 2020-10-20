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
const int MN = 200010;

vi g[MN];
int memo[MN][2];

int dp(int u, int p, int b) {
	if (memo[u][b] != -1)
		return memo[u][b];
	int sum = 0;
	for (int v : g[u]) if (v != p)
		sum += dp(v, u, 0);
	if (b) return memo[u][b] = sum;
	int ans = sum;
	for (int v : g[u]) if (v != p)
		ans = max(ans, sum - dp(v, u, 0) + dp(v, u, 1) + 1);
	return memo[u][b] = ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef UTP
	freopen("input.txt", "r", stdin);
	#endif
	int n; cin >> n;
	fori(i, 0, n - 1) {
		int u; cin >> u; u--;
		int v; cin >> v; v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	memset(memo, -1, sizeof memo);
	int ans = dp(0, -1, 0);
	cout << ans << endl;
	return 0;
}
