// O(V * E * E)

const int MN = 100;
const int oo = 1e9;

int n, s, t, res[MN][MN];
int f, dist[MN], p[MN];

void augment(int v, int minEdge) {
	if (v == s) { f = minEdge; return; }
	if (p[v] != -1) {
		augment(p[v], min(minEdge, res[p[v]][v]));
		res[p[v]][v] -= f; res[v][p[v]] += f;
	}
}

int maxFlow() {
	int mf = 0;
	while (true) {
		f = 0;
		memset(p, -1, sizeof p);
		memset(dist, -1, sizeof dist);
		dist[s] = 0;
		queue<int> q; q.push(s);
		while (!q.empty()) {
			int u = q.front(); q.pop();
			if (u == t) break;
			for (int v = 0; v < n; v++) {
				if (res[u][v] > 0 && dist[v] == -1) {
					dist[v] = dist[u] + 1;
					q.push(v);
					p[v] = u;
				}
			}
		}
		augment(t, oo);
		if (f == 0) break;
		mf += f;
	}
	return mf;
}