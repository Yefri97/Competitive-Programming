struct Vertex {
	map<char,int> next;
	int par;
	Vertex(int par = -1) : par(par) {}
};

vector<Vertex> tree;

void add_string(string s) {
	int u = 0;
	for (char c : s) {
		if (!tree[u].next.count(c)) {
			tree[u].next[c] = SZ(tree);
			tree.push_back(Vertex(u));
		}
		u = tree[u].next[c];
	}
}

tree.clear(); tree.push_back(Vertex()); // don't forget!!