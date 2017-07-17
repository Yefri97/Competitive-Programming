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

const int oo = 1e9, mxn = 30;

int dfsNumberCounter, numSCC;
vi g[mxn], dfs_num, dfs_low, visited, S;
vector<string> vs;

void tarjanSCC(int u) {
	dfs_num[u] = dfs_low[u] = dfsNumberCounter++;
	S.push_back(u);
	visited[u] = 1;
	fori(i, 0, g[u].size()) {
		int v = g[u][i];
		if (dfs_num[v] == -1)
			tarjanSCC(v);
		if (visited[v])
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
	}

	if (dfs_low[u] == dfs_num[u]) {
		int v = S.back(); S.pop_back(); visited[v] = 0;
		cout << vs[v];
		while (u != v) {
			v = S.back(); S.pop_back(); visited[v] = 0;
			cout << ", " << vs[v];
		}
		cout << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, m, cs = 0;
	while (cin >> n >> m && n) {
		if (cs) cout << endl;
		int cnt = 1;
		map<string, int> mapper;
		fori(i, 0, n) g[i].clear();
		vs.clear();
		while (m--) {
			string a, b; cin >> a >> b;
			if (mapper[a] == 0)	mapper[a] = cnt++, vs.push_back(a);
			if (mapper[b] == 0) mapper[b] = cnt++, vs.push_back(b);
			int x = mapper[a], y = mapper[b]; x--; y--;
			g[x].push_back(y);
		}
		// SCC
		dfs_num.assign(n, -1); dfs_low.assign(n, 0); visited.assign(n, 0);
		dfsNumberCounter = numSCC = 0;
		cout << "Calling circles for data set " << ++cs << ":" << endl;
		fori(i, 0, n)
			if (dfs_num[i] == -1)
				tarjanSCC(i);
	}
	return 0;
}