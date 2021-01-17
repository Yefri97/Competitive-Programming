vi g[MN];
int dfsCnt = 0;
int from[MN], to[MN];
int dfs_num[MN], dfs_low[MN], is_bridge[MN];

void get_bridges(int u, int p) {
	dfs_num[u] = dfs_low[u] = dfsCnt++;
	for (int e : g[u]) {
		int v = from[e] + to[e] - u;
		if (dfs_num[v] == -1) {
			get_bridges(v, u);
			if (dfs_low[v] > dfs_num[u])
				is_bridge[e] = 1;
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		} else if (v != p) {
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);
		}
	}
}

memset(dfs_num, -1, sizeof dfs_num);
fori(i, 0, n) if (dfs_num[i] == -1)
	get_bridges(i, -1);