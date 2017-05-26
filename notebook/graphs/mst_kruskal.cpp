// O(log(V) * E)
struct Edge {
	int w, a, b;
	Edge() {}
	Edge(int _w, int _a, int _b) : w(_w), a(_a), b(_b) {}
	bool operator < (const Edge &o) const { return w < o.w; }
};

int mst_kruskal(vector<Edge> &EdgeList, int V, int E) {
	sort(EdgeList.begin(), EdgeList.end());
	int cost = 0;
	UnionFind UF(V);
	fori(i, 0, E) {
		Edge front = EdgeList[i];
		if (!UF.isSameSet(front.a, front.b)) {
			cost += front.w;
			UF.unionSet(front.a, front.b);
		}
	}
	return cost;
}