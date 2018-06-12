#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;
const int MN = 1000010;
const int ML = 21;

int k;
int h[MN], a[MN];
int par[MN][ML];
vi g[MN];

void dfs(int u, int p) {
	par[u][0] = p;
	if (p != -1) h[u] = h[p] + 1;
	for (int i = 1; i < ML; i++)
		if (par[u][i - 1] != -1)
			par[u][i] = par[par[u][i - 1]][i - 1];
	for (int v : g[u]) if (v != p)
		dfs(v, u);
}

int doit(int u) {
	for (int i = ML - 1; i >= 0; i--)
		if (par[u][i] != -1 && a[par[u][i]] == 0)
			u = par[u][i];
	return par[u][0];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, k; cin >> n >> k;
	fori(i, 0, n - 1) {
		int u, v; cin >> u >> v; u--; v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	memset(par, -1, sizeof par);
	dfs(n - 1, -1);
	a[n - 1] = 1;
	for (int i = n - 2, c = n - k - 1; i >= 0; i--) {
		if (a[i] == 1) continue;
		int j = doit(i);
		int d = h[i] - h[j];
		if (d > c) continue;
		c -= d;
		int u = i;
		while (u != j) {
			a[u] = 1;
			u = par[u][0];
		}
	}
	fori(i, 0, n) if (a[i] == 0)
		cout << i + 1 << " ";
	cout << endl;
	return 0;
}
