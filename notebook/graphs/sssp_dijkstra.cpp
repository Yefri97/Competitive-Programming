// O(log(V) * E)
vi dijkstra(vector<vii> &g, int V, int s) {
	vi dist(V, INF); dist[s] = 0;
	priority_queue< ii, vector<ii>, greater<ii> > pq; pq.push(ii(0, s));
	while (!pq.empty()) {
		ii front = pq.top(); pq.pop();
		int d = front.first, u = front.second;
		if (d > dist[u]) continue;
		for (int i = 0; i < g[u].size(); i++) {
			ii v = g[u][i];
			if (dist[v.first] > dist[u] + v.second) {
				dist[v.first] = dist[u] + v.second;
				pq.push(ii(dist[v.first], v.first));
			}
		}
	}
	return dist;
}