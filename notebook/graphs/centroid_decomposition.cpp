// O(n * log(n))
vector<int> g[MN], ctree[MN];
vector<ii> lcen[MN];
int taken[MN], par[MN], szt[MN];

int calc_list_centroid(int s, int u, int p, int dist) {
	lcen[u].push_back(ii(s, dist));
	for (int v : g[u]) {
		if (v == p || taken[v]) continue;
		calc_list_centroid(s, v, u, dist + value[v]);
	}
}

int get_size(int u, int p) {
	szt[u] = 1;
	for (int v : g[u]) {
		if (v != p && !taken[v]) szt[u] += get_size(v, u);
	}
	return szt[u];
}

void dfs(int u, int p, int sz) {
	if (sz == -1) sz = get_size(u, -1);
	for (int v : g[u]) {
		if(!taken[v] && 2 * szt[v] >= sz) {
			szt[u] = 0; dfs(v, p, sz); return;
		}
	}
	if (p != -1) ctree[p].push_back(u);
	calc_list_centroid(u, u, -1, 0);
	taken[u] = 1; par[u] = p;
	for (int v : g[u]) {
		if (!taken[v]) dfs(v, u, -1);
	}
}
