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

const int oo = 1e9, mxn = 100010;

int dfsNumberCounter, numSCC;
vi g[mxn], ng[mxn], dfs_num, dfs_low, visited, S, scc;

void tarjanSCC(int u) {
	dfs_num[u] = dfs_low[u] = dfsNumberCounter++;
	S.push_back(u);
	visited[u] = 1;
	fori(i, 0, g[u].size()) {
		int v = g[u][i];
		if (dfs_num[v] == -1)
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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		fori(i, 0, n) g[i].clear();
		while (m--) {
			int a, b; cin >> a >> b; a--; b--;
			g[a].push_back(b);
		}
		// SCC
		scc.assign(n, 0);
		dfs_num.assign(n, -1); dfs_low.assign(n, 0); visited.assign(n, 0);
		dfsNumberCounter = numSCC = 0;
		fori(i, 0, n)
			if (dfs_num[i] == -1)
				tarjanSCC(i);
		// Contraction
		fori(i, 0, numSCC) ng[i].clear();
		vi in(numSCC);
		fori(u, 0, n) {
			fori(i, 0, g[u].size()) {
				int v = g[u][i];
				if (scc[u] != scc[v]) {
					ng[scc[u]].push_back(scc[v]);
					in[scc[v]]++;
				}
			}
		}
		int ans = 0;
		fori(i, 0, numSCC)
			ans += (in[i] == 0);
		cout << ans << endl;
	}
	return 0;
}