#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9, MN = 200010;

int vis[MN];
vi g[MN], a[MN];

void dfs(int u, int c) {
	vis[u] = 1;
	a[c].push_back(u);
	for (int v : g[u]) {
		if (!vis[v])
			dfs(v, c);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, m; cin >> n >> m;
	fori(i, 0, m) {
		int u, v; cin >> u >> v; u--; v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int c = 0;
	fori(i, 0, n) {
		if (!vis[i]) {
			dfs(i, c);
			c++;
		}
	}
	int ans = 0;
	fori(i, 0, c) {
		int f = 1;
		for (int id : a[i])
			f &= (g[id].size() == 2);
		ans += f;
	}
	cout << ans << endl;
	return 0;
}
