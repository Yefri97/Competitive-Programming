#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))
#define sq(x) (x) * (x)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int oo = 1e9, MAXN = 50010, UNVISITED = -1;

int dfsNumberCounter, numSCC, scc[MAXN];
int root[MAXN], dp[MAXN], val[MAXN];
vi dfs_num, dfs_low, S, visited;
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
		int cnt = 0;
		root[numSCC] = oo;
		while (true) {
			int v = S.back(); S.pop_back(); visited[v] = 0;
			scc[v] = numSCC;
			root[numSCC] = min(root[numSCC], v);
			cnt++;
			if (u == v) break;
		}
		val[numSCC] = cnt;
		numSCC++;
	}
}

int dfs(int u) {
	if (dp[u] != -1) return dp[u];
	int ans = val[u];
	fori(i, 0, ng[u].size())
		ans += dfs(ng[u][i]);
	return dp[u] = ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t, cs = 0; cin >> t;
	while (t--) {
		int n; cin >> n;
		fori(i, 0, n) g[i].clear(), ng[i].clear();
		fori(i, 0, n) {
			int a, b; cin >> a >> b; a--; b--;
			g[a].push_back(b);
		}
		/* Strongly Connected Components */
		int V = n;
		dfs_num.assign(V, UNVISITED); dfs_low.assign(V, 0); visited.assign(V, 0);
		dfsNumberCounter = numSCC = 0;
		fori(i, 0, V)
			if (dfs_num[i] == UNVISITED)
				tarjanSCC(i);
		/* Contracted graph */
		fori(u, 0, n)
			fori(i, 0, g[u].size())
				if (scc[u] != scc[g[u][i]])
					ng[scc[u]].push_back(scc[g[u][i]]);
		/* Dynamic Programming */
		memset(dp, -1, sizeof dp);
		int ans = 0, mx = 0;
		fori(i, 0, numSCC) {
			int x = dfs(i);
			if (x > mx) {
				mx = x;
				ans = root[i];
			} else if (x == mx) {
				ans = min(ans, root[i]);
			}
		}
		cout << "Case " << ++ cs << ": " << ans + 1 << endl;
	}
	return 0;
}