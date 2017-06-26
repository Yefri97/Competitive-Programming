// Topological sort
#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int INF = 1e9;

vector<vi> g;
vi visited, ts;

void dfs(int u) {
	visited[u] = 1;
	fori(i, 0, g[u].size()) {
		int v = g[u][i];
		if (!visited[v])
			dfs(v);
	}
	ts.push_back(u + 1);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, m;
	while (cin >> n >> m && (n || m)) {
		g.assign(n, vi());
		while (m--) {
			int a, b; cin >> a >> b; a--; b--;
			g[a].push_back(b);
		}
		visited.assign(n, 0);
		ts.clear();
		fori(i, 0, n)
			if (!visited[i])
				dfs(i);
		cout << ts[n - 1];
		fori(i, 1, n)
			cout << " " << ts[n - i - 1];
		cout << endl;
	}
	return 0;
}