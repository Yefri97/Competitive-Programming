// O(V + E)
#define DFS_WHITE -1
#define DFS_GRAY 0
#define DFS_BLACK 1

vector<vi> g;

ii backEdge;
vi dfs_num, dfs_parent;

bool cycleCheck(int u) {
	dfs_num[u] = DFS_GRAY;
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		if (dfs_num[v] == DFS_WHITE) {
			dfs_parent[v] = u;
			if (cycleCheck(v)) return true;
		} else if (dfs_num[v] == DFS_GRAY) {
			backEdge = ii(u, v);
			return true;
		}
	}
	dfs_num[u] = DFS_BLACK;
	return false;
}