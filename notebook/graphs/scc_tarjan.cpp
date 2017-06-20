const int MAXN = /*...*/, UNVISITED = -1;

int dfsNumberCounter, numSCC, scc[MAXN];
vi dfs_num, dfs_low, S, visited;
vi g[MAXN];

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

int main() {
	/* ... */
	dfs_num.assign(V, UNVISITED); dfs_low.assign(V, 0); visited.assign(V, 0);
	dfsNumberCounter = numSCC = 0;
	fori(i, 0, V)
		if(dfs_num[i] == UNVISITED)
			tarjanSCC(i);
	/* ... */
}