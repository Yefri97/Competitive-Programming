#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9, MX = 100010;

struct Node {

	int best;
	Node* children[2];

	Node() {
		best = oo;
		children[0] = children[1] = NULL;
	}

};

Node* root[MX];

void insert(int x, int k) {
	Node* u = root[k];
	u->best = min(u->best, x);
	for (int i = 16; i >= 0; i--) {
		int c = (x >> i) & 1;
		if (u->children[c] == NULL)
			u->children[c] = new Node();
		u = u->children[c];
		u->best = min(u->best, x);
	}
}

int query(int x, int k, int s) {
	Node* u = root[k];
	if (x % k > 0 || u->best > s - x) return -1;
	int ans = 0;
	for (int i = 16; i >= 0; i--) {
		int c = (x >> i) & 1;
		Node* a = u->children[1 - c];
		Node* b = u->children[c];
		if (a != NULL && a->best <= s - x) {
			u = a;
			ans |= (1 - c) << i;
		} else {
			u = b;
			ans |= c << i;
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	// Init
	vector<vi> divisors(MX);
	for (int i = 1; i < MX; i++) {
		for (int j = i; j < MX; j += i)
			divisors[j].push_back(i);
		root[i] = new Node();
	}
	// Queries
	int q; cin >> q;
	while (q--) {
		int t; cin >> t;
		if (t == 1) {
			int x; cin >> x;
			for (int d : divisors[x])
				insert(x, d);
		} else {
			int x, k, s; cin >> x >> k >> s;
			int ans = query(x, k, s);
			cout << ans << endl;
		}
	}
	return 0;
}
