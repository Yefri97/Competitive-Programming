// O(V)
int g[MN][MN];
stack<int> s;

void dfs(int u) {
	for (int v = 0; v < n; v++) if (g[u][v]) {
		if (used[u][v]) continue;
		used[u][v] = 1;
		dfs(v);
	}
	s.push(u);
}