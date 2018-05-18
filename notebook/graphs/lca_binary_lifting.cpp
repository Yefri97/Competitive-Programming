const int MN = 200000;
const int ML = 18;

vi g[MN];
int h[MN];
int par[MN][ML]; // initialize -1

void dfs(int u, int p) {
	par[u][0] = p;
	if (p != -1) h[u] = h[p] + 1;
	for (int i = 1; i < ML; i++)
		if (par[u][i - 1] != -1)
			par[u][i] = par[par[u][i - 1]][i - 1];
	for (int v : g[u]) if (v != p)
		dfs(v, u);
}

int lca(int u, int v) {
	if (h[u] < h[v])
		swap(u, v);
	for (int i = ML - 1; i >= 0; i--)
		if (par[u][i] != -1 && h[par[u][i]] >= h[v])
			u = par[u][i];
	// h[u] = h[v]
	if (u == v) return u;
	for (int i = ML - 1; i >= 0; i--)
		if (par[u][i] != par[v][i])
			u = par[u][i], v = par[v][i];
	return par[u][0];
}

int dist(int u, int v) {
	return h[u] + h[v] - 2 * h[lca(u, v)];
}