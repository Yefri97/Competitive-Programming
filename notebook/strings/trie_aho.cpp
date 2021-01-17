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

/* Aho Corasick */

struct Vertex {
	map<char,int> next, go;
	int par, link;
	char pch;
	vector<int> leaf;
	Vertex(int par = -1, char pch = -1) : par(par), pch(pch), link(-1) {}
};

vector<Vertex> tree;

void add_string(string s, int id) {
	int u = 0;
	for (char c : s) {
		if (!tree[u].next.count(c)) {
			tree[u].next[c] = tree.size();
			tree.push_back(Vertex(u, c));
		}
		u = tree[u].next[c];
	}
	tree[u].leaf.push_back(id);
}

int go(int v, char c);

int get_link(int u) {
	if (tree[u].link != -1) return tree[u].link;
	if (u == 0 || tree[u].par == 0) tree[u].link = 0;
	else tree[u].link = go(get_link(tree[u].par), tree[u].pch);
	return tree[u].link;
}

int go(int u, char c) {
	if (tree[u].go.count(c)) return tree[u].go[c];
	if (tree[u].next.count(c)) tree[u].go[c] = tree[u].next[c];
	else tree[u].go[c] = (u == 0 ? 0 : go(get_link(u), c));
	return tree[u].go[c];
}