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

const int oo = 1e9, mxn = 100010;

int dfsNumberCounter;
vi g[mxn], dfs_num, dfs_low, dfs_parent;
vii ans;

void bridges(int u) {
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
	fori(j, 0, g[u].size()) {
		int v = g[u][j];
		if (dfs_num[v] == -1) {
			dfs_parent[v] = u;
			bridges(v);
			if (dfs_low[v] > dfs_num[u])
				ans.push_back(ii(min(u, v), max(u, v)));
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		} else if (v != dfs_parent[u]) {
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	while (cin >> n) {
		fori(i, 0, n) g[i].clear();
		fori(i, 0, n) {
			int x; cin >> x;
			int k;
			char c;
			cin >> c >> k >> c;
			fori(i, 0, k) {
				int y; cin >> y;
				g[x].push_back(y);
				g[y].push_back(x);
			}
		}
		ans.clear();
		// bridges
		dfsNumberCounter = 0; dfs_num.assign(n, -1);
		dfs_low.assign(n, 0); dfs_parent.assign(n, 0);
		fori(i, 0, n)
			if (dfs_num[i] == -1)
				bridges(i);

		sort(ans.begin(), ans.end());
		cout << ans.size() << " critical links" << endl;
		fori(i, 0, ans.size())
			cout << ans[i].first << " - " << ans[i].second << endl;
		cout << endl;
	}
	return 0;
}