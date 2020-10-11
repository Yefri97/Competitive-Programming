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
int vis[MN];

void dfs(int u) {
	vis[u] = 1;
	for (int v : g[u]) if (!vis[v])
		dfs(v);
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
	vi ans;
	fori(i, 0, n) if (!vis[i]) {
		dfs(i);
		ans.push_back(i + 1);
	}
	cout << SZ(ans) - 1 << endl;
	fori(i, 1, SZ(ans))
		cout << ans[i] << " " << ans[i - 1] << endl;
	return 0;
}
