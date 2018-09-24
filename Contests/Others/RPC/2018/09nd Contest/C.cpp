#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define SZ(v) (int)v.size()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9, MN = 1010;

int n, m;
int from[MN], to[MN], weight[MN], par[MN];
vi g[MN];

int can(int x) {
	vi vis(n); vis[0] = 1;
	queue<int> q; q.push(0);
	memset(par, -1, sizeof par);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		if (u == n - 1) return true;
		for (int e : g[u]) {
			if (weight[e] < x) continue;
			int v = from[e] + to[e] - u;
			if (vis[v]) continue;
			vis[v] = 1;
			par[v] = u;
			q.push(v);
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	fori(i, 0, m) {
		cin >> from[i] >> to[i] >> weight[i];
		g[from[i]].push_back(i);
		g[to[i]].push_back(i);
	}
	int lo = 0, hi = oo;
	while (hi - lo > 1) {
		int mi = (hi + lo) / 2;
		if (can(mi)) lo = mi;
		else hi = mi;
	}
	can(lo);
	set<int> nodes;
	set<ii> edges;
	int u = n - 1;
	while (par[u] != -1) {
		nodes.insert(u);
		edges.insert(ii(u, par[u]));
		edges.insert(ii(par[u], u));
		u = par[u];
	}
	nodes.insert(u);
	int first = 1;
	fori(i, 0, m) {
		if (!edges.count(ii(from[i], to[i])) && (nodes.count(from[i]) || nodes.count(to[i]))) {
			if (!first) cout << " "; first = 0;
			cout << i;
		}
	}
	if (first) cout << "none";
	cout << endl;
	return 0;
}