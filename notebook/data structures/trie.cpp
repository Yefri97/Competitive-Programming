const int MA = 26, MX = 500000;

struct Node {
    bool leaf;
    int best;
    int children[MA];
    Node() {
        leaf = false;
        best = -1;
        memset(children, -1, sizeof children);
    }
};

int num_nodes;
vector<Node> T;
//Node T[MX];

void insert_trie(string s, int w) {
    int u = 0;
    for (int i = 0; i < s.size(); i++) {
        int c = s[i] - 'a';
        if (T[u].children[c] == -1) {
            T.push_back(Node());
            num_nodes++;
            T[u].children[c] = num_nodes;
        }
        T[u].best = max(T[u].best, w);
        u = T[u].children[c];
    }
    T[u].leaf = true;
}

int query_trie(string s) {
    int u = 0;
    for (int i = 0; i < s.size(); i++) {
        int c = s[i] - 'a';
        if (T[u].children[c] == -1)
            return -1;
        u = T[u].children[c];
    }
    return T[u].best;
}
