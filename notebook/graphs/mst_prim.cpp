// O(log(V) * E)
int mst_prim(vector<vii> &AdjList, int V, int E) {
	vi taken(V);
	priority_queue<ii> pq; pq.push(ii(0, 0));
	int cost = 0;
	while (!pq.empty()) {
		ii front = pq.top(); pq.pop();
		int w = -front.first, u = front.second;
		if (!taken[u]) {
			cost += w;
			taken[u] = 1;
			fori(i, 0, AdjList[u].size()) {
				ii v = AdjList[u][i];
				if (!taken[v.first]) pq.push(ii(-v.second, v.first));
			}
		}
	}
	return cost;
}