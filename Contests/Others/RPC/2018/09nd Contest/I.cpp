#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9, MN = 100000, UNVISITED = -1;

int dfsNumberCounter, numSCC, scc[MN], sz[MN];
int dfs_num[MN], dfs_low[MN], visited[MN];
vi S, g[MN], g2[MN];
int enemy[MN], bad[MN], dp[MN], send[MN];

void tarjanSCC(int u) {
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
	S.push_back(u);
	visited[u] = 1;
	fori(j, 0, g[u].size()) {
		int v = g[u][j];
		if (dfs_num[v] == UNVISITED)
			tarjanSCC(v);
		if (visited[v])
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
	}
	if (dfs_low[u] == dfs_num[u]) {
		while (true) {
			int v = S.back(); S.pop_back(); visited[v] = 0;
			scc[v] = numSCC;
			bad[numSCC] |= enemy[v];
			sz[numSCC]++;
			if (u == v) break;
		}
		numSCC++;
	}
}

int dfs(int u) {
	if (dp[u] != -1) return dp[u];
	int ok = !bad[u];
	for (int v : g2[u])
		ok &= dfs(v);
	if (ok) {
		send[u] += sz[u];
		for (int v : g2[u]) {
			send[u] += send[v];
			send[v] = 0;
		}
	}
	return dp[u] = ok;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, e, m; cin >> n >> e >> m;
	fori(i, 0, m) {
		int u, v; cin >> u >> v;
		g[u].push_back(v);
	}
	fori(i, 0, e) {
		int x; cin >> x;
		enemy[x] = 1;
	}
	memset(dfs_num, -1, sizeof dfs_num);
	dfsNumberCounter = numSCC = 0;
	fori(i, 0, n)
		if (dfs_num[i] == UNVISITED)
			tarjanSCC(i);
	fori(u, 0, n) {
		for (int v : g[u]) if (scc[u] != scc[v])
			g2[scc[u]].push_back(scc[v]);
	}
	memset(dp, -1, sizeof dp);
	fori(i, 0, numSCC) if (dp[i] == -1)
		dfs(i);
	int ans = n - e;
	fori(i, 0, numSCC)
		ans -= max(0, send[i] - 1);
	cout << ans << endl;
	return 0;
}
