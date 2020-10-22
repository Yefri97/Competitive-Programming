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
int dp[MN];

int dfs(int u, int p) {
	int mx = 0;
	for (int v : g[u]) if (v != p) {
		int d = dfs(v, u);
		dp[u] = max(dp[u], mx + d + 1);
		mx = max(mx, d + 1);
	}
	return mx;
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
	int ans = dfs(0, -1);
	fori(i, 0, n)
		ans = max(ans, dp[i]);
	cout << ans << endl;
	return 0;
}
