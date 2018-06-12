#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))
#define sq(x) (x) * (x)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int oo = 1e9, mxn = 110;

struct Node {
	int u, d, c;
	Node() {}
	Node(int _u, int _d, int _c) : u(_u), d(_d), c(_c) {}
	bool operator < (const Node &o) const {
		if (d != o.d) return d > o.d;
		return c > o.c;
	}
};

vi taken;
priority_queue<Node> pq;
vii g[mxn];

void process(Node curr) {
	taken[curr.u] = 1;
	fori(i, 0, g[curr.u].size()) {
		ii v = g[curr.u][i];
		if (!taken[v.first])
			pq.push(Node(v.first, curr.d + 1, v.second));
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, m;
	while (cin >> n >> m) {
		map<string, int> mapper;
		mapper["english"] = 0;
		int id = 0;
		fori(i, 0, n) {
			string name; cin >> name;
			mapper[name] = ++id;
		}
		n++;
		fori(i, 0, n) g[i].clear();
		fori(i, 0, m) {
			string a, b; cin >> a >> b;
			int c; cin >> c;
			int u = mapper[a], v = mapper[b];
			g[u].push_back(ii(v, c));
			g[v].push_back(ii(u, c));
		}
		// Prim's algorithm
		taken.assign(n, 0);
		process(Node(0, 0, 0));
		int cost = 0;
		while (!pq.empty()) {
			Node curr = pq.top(); pq.pop();
			if (!taken[curr.u])
				cost += curr.c, process(curr);
		}
		bool b = true;
		fori(i, 0, n) b &= taken[i];
		if (b)
			cout << cost << endl;
		else
			cout << "Impossible" << endl;
	}
	return 0;
}