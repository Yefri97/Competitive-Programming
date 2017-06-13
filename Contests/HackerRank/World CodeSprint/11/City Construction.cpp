#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int INF = 1e9, MAXN = 50010, UNVISITED = -1;

bitset<MAXN> dp[MAXN];

int dfsNumberCounter, numSCC, scc[MAXN];
vi dfs_num, dfs_low, S, visited, ts;
vi g[MAXN], ng[MAXN];

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
			if (u == v) break;
		}
		numSCC++;
	}
}

void dfs(int u) {
	visited[u] = 1;
	fori(i, 0, ng[u].size()) {
		int v = ng[u][i];
		if (!visited[v])
			dfs(v);
	}
	ts.push_back(u);
}

vector<ii> queries;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, m; cin >> n >> m;
	fori(i, 0, m) {
		int u, v; cin >> u >> v; u--; v--;
		g[u].push_back(v);
	}
	int q; cin >> q;
	fori(i, 0, q) {
		int type; cin >> type;
		if (type == 1) {
			int x, d; cin >> x >> d; x--;
			if (d == 0)
				g[x].push_back(n);
			else
				g[n].push_back(x);
			n++;
		} else {
			int x, y; cin >> x >> y; x--; y--;
			queries.push_back(ii(x, y));
		}
	}
	/* Strongly Connected Components */
	int V = n;
	dfs_num.assign(V, UNVISITED); dfs_low.assign(V, 0); visited.assign(V, 0);
	dfsNumberCounter = numSCC = 0;
	fori(i, 0, V)
		if(dfs_num[i] == UNVISITED)
			tarjanSCC(i);
	/* Contracted graph */
	fori(u, 0, n) {
		fori(i, 0, g[u].size())
			if (scc[u] != scc[g[u][i]])
				ng[scc[u]].push_back(scc[g[u][i]]);
	}
	/* Topological Sort */
	visited.assign(numSCC, 0);
	fori(u, 0, numSCC)
		if (!visited[u])
			dfs(u);
	/* Dynammic Programming */
	fori(u, 0, ts.size()) {
		dp[u].set(u);
		fori(i, 0, ng[u].size())
			dp[u] |= dp[ng[u][i]];
	}
	/* Answer the queries */
	fori(i, 0, queries.size()) {
		int x = queries[i].first, y = queries[i].second;
		cout << ( dp[scc[x]].test(scc[y]) ? "Yes" : "No" ) << endl;
	}
	return 0;
}