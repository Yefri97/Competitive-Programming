#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9, MN = 100010;

vi g[MN];
int par[MN];

void dfs(int u, int p) {
	par[u] = 1;
	for (int v : g[u]) {
		if (v == p) continue;
		dfs(v, u);
		par[u] ^= par[v];
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	fori(i, 0, n - 1) {
		int u, v; cin >> u >> v; u--; v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	if (n % 2) { cout << -1 << endl; return 0; }
	dfs(0, -1);
	int ans = 0;
	fori(i, 0, n)
		ans += (par[i] == 0);
	cout << ans - 1 << endl;
	return 0;
}
