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

const int oo = 1e9, mxn = 50;

vi g[mxn], team, visited;

void dfs(int u) {
	team.push_back(u + 1);
	visited[u] = 1;
	fori(i, 0, g[u].size()) {
		int v = g[u][i];
		if (!visited[v])
			dfs(v);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, m; cin >> n >> m;
	while (m--) {
		int a, b; cin >> a >> b; a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	vector< vector< vi > > ans(5);
	visited.assign(n, 0);
	fori(u, 0, n) {
		if (!visited[u]) {
			dfs(u);
			ans[team.size() > 3 ? 4 : team.size()].push_back(team);
			team.clear();
		}
	}
	if (ans[4].size() || ans[2].size() > ans[1].size()) {
		cout << -1 << endl;
	} else {
		fori(i, 0, ans[3].size())
			cout << ans[3][i][0] << " " << ans[3][i][1] << " " << ans[3][i][2] << endl;
		fori(i, 0, ans[2].size())
			cout << ans[2][i][0] << " " << ans[2][i][1] << " " << ans[1][i][0] << endl;
		for (int i = ans[2].size(); i < ans[1].size(); i += 3)
			cout << ans[1][i][0] << " " << ans[1][i + 1][0] << " " << ans[1][i + 2][0] << endl;
	}
	return 0;
}