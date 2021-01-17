// Given a tree, every vertex has color. Query is how many vertices in subtree of vertex v are colored with color c?
int cnt[maxn];

void add(int u, int p, int inc, int bigChild = -1) {
	cnt[col[u]] += inc;
	for (int v : g[u]) if (v != p) {
		if (v == bigChild) continue;
		add(v, u, inc);
	}
}

void dfs(int u, int p, int keep) {
	int bigChild = -1;
	for (int v : g[u]) if (v != p) {
		if (bigChild == -1 || sz[v] > sz[bigChild])
			bigChild = v;
	}
	for (int v : g[u]) if (v != p) {
		if (v == bigChild) continue;
		dfs(v, u, 0);
	}
	if (bigChild != -1) dfs(bigChild, u, 1);
	add(u, p, 1, bigChild);
    // now cnt[c] is the number of vertices in subtree of vertex v that has color c. You can answer the queries easily.
	if (keep == 0) add(u, p, -1);
}