// Min Cost Max Flow
// https://github.com/jaehyunp/stanfordacm/blob/master/code/MinCostMaxFlow.cc

// O(V * V * E)
struct Edge {
	int u, v;
	long long cap, flow;
	Edge() {}
	Edge(int u, int v, long long cap): u(u), v(v), cap(cap), flow(0) {}
};

struct Dinic {
	int n;
	vector<Edge> edges;
	vector< vector<int> > g;
	vector<int> d, pt;
	Dinic(int _n): n(_n), edges(0), g(_n), d(_n), pt(_n) {}

	void add_edge(int u, int v, long long cap) {
		edges.push_back(Edge(u, v, cap));
		g[u].push_back(edges.size() - 1);
		edges.push_back(Edge(v, u, 0));
		g[v].push_back(edges.size() - 1);
	}

	bool bfs(int S, int T) {
		queue<int> q; q.push(S);
		fill(d.begin(), d.end(), -1);
		d[S] = 0;
		while(!q.empty()) {
			int u = q.front(); q.pop();
			if (u == T) break;
			for (int k: g[u]) {
				Edge e = edges[k];
				if (e.flow < e.cap && d[e.v] == -1) {
					d[e.v] = d[e.u] + 1;
					q.push(e.v);
				}
			}
		}
		return (d[T] != -1);
	}

	long long dfs(int u, int T, long long flow = -1) {
		if (u == T || flow == 0) return flow;
		for (int &i = pt[u]; i < SZ(g[u]); ++i) {
			Edge &e = edges[g[u][i]];
			Edge &oe = edges[g[u][i]^1];
			if (d[e.v] == d[e.u] + 1) {
				long long amt = e.cap - e.flow;
				if (flow != -1 && amt > flow) amt = flow;
				if (long long pushed = dfs(e.v, T, amt)) {
					e.flow += pushed;
					oe.flow -= pushed;
					return pushed;
				}
			}
		}
		return 0;
	}

	long long max_flow(int S, int T) {
		long long total = 0;
		while (bfs(S, T)) {
			fill(pt.begin(), pt.end(), 0);
			while (long long flow = dfs(S, T))
				total += flow;
		}
		return total;
	}
};