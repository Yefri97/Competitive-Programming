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

const ll oo = 1e16;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef UTP
	freopen("input.txt", "r", stdin);
	#endif
	int n, m, q; cin >> n >> m >> q;
	ll g[n][n];
	fori(i, 0, n) fori(j, 0, n)
		g[i][j] = (i == j ? 0 : oo);
	fori(i, 0, m) {
		int u; cin >> u; u--;
		int v; cin >> v; v--;
		ll c; cin >> c;
		g[u][v] = min(g[u][v], c);
		g[v][u] = min(g[v][u], c);
	}
	fori(k, 0, n)
		fori(i, 0, n)
			fori(j, 0, n)
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
	while (q--) {
		int u; cin >> u; u--;
		int v; cin >> v; v--;
		if (g[u][v] < oo)
			cout << g[u][v] << endl;
		else
			cout << -1 << endl;
	}
	return 0;
}
