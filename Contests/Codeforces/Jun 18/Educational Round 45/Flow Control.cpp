#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9, MN = 200010;

int a[MN], s[MN], f[MN];
int x[MN], y[MN];
int vis[MN], par[MN];
vi g[MN];

void dfs(int u, int p) {
	vis[u] = 1;
	par[u] = p;
	for (int e : g[u]) {
		int v = x[e] + y[e] - u;
		if (vis[v]) continue;
		dfs(v, u);
		f[e] = a[v] + s[v];
		s[u] += f[e];
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	fori(i, 0, n)
		cin >> a[i];
	int acc = accumulate(a, a + n, 0);
	if (acc != 0) { cout << "Impossible" << endl; return 0; }
	int m; cin >> m;
	fori(i, 0, m) {
		cin >> x[i] >> y[i]; x[i]--; y[i]--;
		g[x[i]].push_back(i);
		g[y[i]].push_back(i);
	}
	dfs(0, -1);
	fori(i, 0, m) if (f[i]) {
		if (par[y[i]] != x[i])
			f[i] *= -1;
	}
	cout << "Possible" << endl;
	fori(i, 0, m)
		cout << f[i] << endl;
	return 0;
}
