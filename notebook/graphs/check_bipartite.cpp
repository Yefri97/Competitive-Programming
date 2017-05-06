// O(V + E)
vector<vi> g;
vi color;

bool bipartiteCheck(int u, int c) {
	color[u] = c;
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		if (color[v] == -1) {
			if (!bipartiteCheck(v, 1 - c)) return false;
		} else if (color[v] == c) {
			return false;
		}
	}
	return true;
}