// O(V * E)
int V;
vector<vii> g;
vector<ll> dist;
vector<bool> neg;

void dfs(int u) {
	neg[u] = true;
	for (int i = 0; i < g[u].size(); i++) {
		ii v = g[u][i];
		if (!neg[v.first])
			dfs(v.first);
	}
}

void bellmanFord(int s) {
	dist.assign(V, INF); dist[s] = 0;

	for (int i = 0; i < V - 1; i++) {
		for (int u = 0; u < V; u++) {
			if (dist[u] == INF) continue;
			for (int j = 0; j < g[u].size(); j++) {
				ii v = g[u][j];
				if (dist[v.first] > dist[u] + v.second)
					dist[v.first] = max(-INF, dist[u] + v.second);
			}
		}
	}

	neg.assign(V, false);
	for (int u = 0; u < V; u++) {
		for (int i = 0; i < g[u].size(); i++) {
			ii v = g[u][i];
			if (!neg[v.first] && dist[u] < INF && dist[v.first] > dist[u] + v.second)
				dfs(v.first);
		}
	}
}