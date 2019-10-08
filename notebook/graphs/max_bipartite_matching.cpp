// O(V * E)
vector<int> g[MN];
int match[MN], vis[MN];

int aug(int u) {
	if (vis[u]) return 0;
	vis[u] = 1;
	for (int v : g[u]) {
		if (match[v] == -1 || aug(match[v])) {
			match[v] = u;
			return 1;
		}
	}
	return 0;
}

int main() {
	/* ... */
	int mcbm = 0;
	memset(match, -1, sizeof match);
	for (int u = 0; u < n; u++) {
		memset(vis, 0, sizeof vis);
		mcbm += aug(u);
	}
	/* ... */
}