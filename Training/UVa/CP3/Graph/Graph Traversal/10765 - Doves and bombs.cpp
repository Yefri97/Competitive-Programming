#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))
#define sq(x) (x) * (x)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int oo = 1e9, mxn = 10010;

int dfsNumberCounter, dfsRoot, rootChildren;
vi g[mxn], dfs_num, dfs_low, dfs_parent, articulation_vertex;

void articulationPoint(int u) {
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
	fori(j, 0, g[u].size()) {
		int v = g[u][j];
		if (dfs_num[v] == -1) {
			dfs_parent[v] = u;
			if (u == dfsRoot) rootChildren++;

			articulationPoint(v);

			if (dfs_low[v] >= dfs_num[u])
				articulation_vertex[u]++;
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		} else if (v != dfs_parent[u]) {
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, k;
	while (cin >> n >> k && n) {
		fori(i, 0, n) g[i].clear();
		int x, y;
		while (cin >> x >> y && x != -1) {
			g[x].push_back(y);
			g[y].push_back(x);
		}
		// articulationPoints
		dfsNumberCounter = 0; dfs_num.assign(n, -1); dfs_low.assign(n, 0);
		dfs_parent.assign(n, 0); articulation_vertex.assign(n, 1);
		fori(i, 0, n) {
			if (dfs_num[i] == -1) {
				dfsRoot = i; rootChildren = 0;
				articulationPoint(i);
				articulation_vertex[dfsRoot] += (rootChildren > 1 ? 1 : -1);
			}
		}
		priority_queue<ii> pq;
		fori(i, 0, n)
			pq.push(ii(articulation_vertex[i], -i));
		fori(i, 0, k) {
			ii top = pq.top(); pq.pop();
			cout << -top.second << " " << top.first << endl;
		}
		cout << endl;
	}
	return 0;
}