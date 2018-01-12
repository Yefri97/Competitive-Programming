#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))
#define sq(x) (x) * (x)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int oo = 1e9, MX = 10010;

int t[MX];
vi g[MX];

int dfs(int u, int c) {
	int ans = 0;
	if (c != t[u]) ans++;
	fori(i, 0, g[u].size()) {
		int v = g[u][i];
		ans += dfs(v, t[u]);
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	fori(u, 1, n) {
		int v; cin >> v; v--;
		g[v].push_back(u);
	}
	fori(i, 0, n)
		cin >> t[i];
	int ans = dfs(0, 0);
	cout << ans << endl;
	return 0;
}