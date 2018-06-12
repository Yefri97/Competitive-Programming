#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9, MN = 300010;

int x, y;
ll s[MN];
vi g[MN];

int dfs(int u, int p) {
	int nxt = (u == x) ? 1 : -1;
	for (int v : g[u]) {
		if (v == p) continue;
		if (dfs(v, u) != -1) nxt = v;
		s[u] += s[v];
	}
	s[u]++;
	return nxt;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n; cin >> n >> x >> y; x--; y--;
	fori(i, 0, n - 1) {
		int u, v; cin >> u >> v; u--; v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	if (n == 1) { cout << 0 << endl; return 0; }
	int nxt = dfs(y, -1);
	ll ans = n * (n - 1) - s[x] * (s[y] - s[nxt]);
	cout << ans << endl;
	return 0;
}
