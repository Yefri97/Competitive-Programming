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

const int oo = 1e9, mxn = 200010;

int taken[mxn], cnt[mxn], init[mxn];
vi g[mxn];

void dfs(int u) {
	taken[u] = 1;
	fori(i, 0, g[u].size()) {
		int v = g[u][i];
		if (!taken[v]) {
			cnt[v]--;
			if (2 * cnt[v] <= init[v])
				dfs(v);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, m, a, b; cin >> n >> m >> a >> b; a--; b--;
	while (m--) {
		int u, v; cin >> u >> v; u--; v--;
		g[u].push_back(v);
		g[v].push_back(u);
		cnt[u]++; cnt[v]++;
		init[u]++; init[v]++;
	}
	dfs(b);
	cout << (taken[a] ? "leave" : "stay") << endl;
	return 0;
}