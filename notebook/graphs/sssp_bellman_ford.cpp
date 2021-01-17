// O(V * E)
int n;
vector<vii> g;
vector<ll> dist;
vector<bool> neg;

void dfs(int u) {
	neg[u] = 1;
	for (int i = 0; i < SZ(g[u]); i++) {
		ii v = g[u][i];
		if (!neg[v.first])
			dfs(v.first);
	}
}

void bellmanFord(int s) {
	dist.assign(n, oo); dist[s] = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int u = 0; u < n; u++) {
			if (dist[u] == oo) continue;
			for (int j = 0; j < SZ(g[u]); j++) {
				ii v = g[u][j];
				if (dist[v.first] > dist[u] + v.second)
					dist[v.first] = max(-oo, dist[u] + v.second);
			}
		}
	}
	neg.assign(n, false);
	for (int u = 0; u < n; u++) {
		for (int i = 0; i < SZ(g[u]); i++) {
			ii v = g[u][i];
			if (!neg[v.first] && dist[u] < oo && dist[v.first] > dist[u] + v.second)
				dfs(v.first);
		}
	}
}