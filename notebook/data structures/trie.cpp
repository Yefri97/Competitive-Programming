// Solve the problem of find v such that v <= lim and v ^ x is maximum
struct Node {
	int best;
	Node* children[2];
	Node() {
		best = oo;
		children[0] = children[1] = NULL;
	}
};

Node* root;

void insert(int x, int k) {
	Node* u = root;
	u->best = min(u->best, x);
	for (int i = 16; i >= 0; i--) {
		int c = (x >> i) & 1;
		if (u->children[c] == NULL)
			u->children[c] = new Node();
		u = u->children[c];
		u->best = min(u->best, x);
	}
}

int query(int x, int lim) {
	Node* u = root;
	int ans = 0;
	for (int i = 16; i >= 0; i--) {
		int c = (x >> i) & 1;
		Node* a = u->children[1 - c];
		Node* b = u->children[c];
		if (a != NULL && a->best <= lim) {
			u = a;
			ans |= (1 - c) << i;
		} else {
			u = b;
			ans |= c << i;
		}
	}
	return ans;
}

void init() {
	root = new Node();
}