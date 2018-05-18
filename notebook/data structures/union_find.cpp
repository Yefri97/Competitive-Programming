struct UnionFind {
	int num;
	vi p, size;
	UnionFind(int n) : p(n, -1), size(n, 1), num(n) {}
	int findSet(int i) { return (p[i] < 0) ? i : (p[i] = findSet(p[i])); }
	void unionSet(int i, int j) {
		int a = findSet(j), b = findSet(i);
		if (a != b) { p[a] = b; size[b] += size[a]; num--; }
	}
	int numSets() { return num; }
	int sizeSet(int i) { return size[findSet(i)]; }
};