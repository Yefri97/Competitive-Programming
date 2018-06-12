#include <bits/stdc++.h>
using namespace std;

const int MA = 2, MX = 1000;

struct Node {
    int children[MA];
    Node() {
        memset(children, -1, sizeof children);
    }
};

int A[MX];
int num_nodes;
vector<Node> T;

void insert_trie(int x) {
    int u = 0;
    for (int i = 16; i >= 0; i--) {
        int c = (x >> i) & 1;
        if (T[u].children[c] == -1) {
            T.push_back(Node());
            T[u].children[c] = ++num_nodes;
        }
        u = T[u].children[c];
    }
}

int query_trie(int x) {
    int u = 0, ans = 0;
    for (int i = 16; i >= 0; i--) {
        int c = (x >> i) & 1, nc = !c;
        if (T[u].children[nc] != -1) {
            u = T[u].children[nc];
            ans |= (1 << i);
        } else {
            u = T[u].children[c];
        }
    }
    return ans;
}

int sum(int i, int j) { return A[j] - (i == 0 ? 0 : A[i - 1]); }

int main() {
    num_nodes = 0;
    T.push_back(Node());
    int n; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> A[i];
    for (int i = 1; i < n; i++)
        A[i] += A[i - 1];
    int ans = 0;
    insert_trie(A[0]);
    for (int i = 1; i < n; i++) {
        for (int j = i; j < n; j++)
            ans = max(ans, query_trie(sum(i, j)));
        for (int j = 0; j <= i; j++)
            insert_trie(sum(j, i));
    }
    cout << ans << endl;
    return 0;
}