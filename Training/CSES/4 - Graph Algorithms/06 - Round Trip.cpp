#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define SZ(X) ((int)X.size())
#define SQ(X) ((X) * (X))
#define all(X) X.begin(), X.end()
#define fori(i,a,b) for(int i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;
const int MN = 100010;

vi g[MN];
int par[MN];

int dfs(int u, int p) {
	par[u] = p;
	for (int v : g[u]) if (v != p) {
		if (par[v] == -1) {
			int cycle = dfs(v, u);
			if (cycle != -1) return cycle;
		} else {
			par[v] = u;
			return v;
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef UTP
	freopen("input.txt", "r", stdin);
	#endif
	int n, m; cin >> n >> m;
	fori(i, 0, m) {
		int u; cin >> u; u--;
		int v; cin >> v; v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	memset(par, -1, sizeof par);
	fori(i, 0, n) if (par[i] == -1) {
		int cycle = dfs(i, i);
		if (cycle != -1) {
			vi ans;
			ans.push_back(cycle);
			int u = par[cycle];
			while (u != cycle) {
				ans.push_back(u);
				u = par[u];
			}
			ans.push_back(u);
			reverse(all(ans));
			cout << SZ(ans) << endl;
			for (int x : ans)
				cout << x + 1 << " ";
			cout << endl;
			return 0;
		}
	}
	cout << "IMPOSSIBLE" << endl;
	return 0;
}
