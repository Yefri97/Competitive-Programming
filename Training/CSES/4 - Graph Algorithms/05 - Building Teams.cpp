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
int col[MN];
 
int dfs(int u, int c) {
	col[u] = c;
	for (int v : g[u]) {
		if (col[v] == -1) {
			int ok = dfs(v, 1 - c);
			if (!ok) return 0;
		} else {
			if (col[v] == c)
				return 0;
		}
	}
	return 1;
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
	memset(col, -1, sizeof col);
	fori(i, 0, n) {
		if (col[i] == -1) {
			int ok = dfs(i, 0);
			if (!ok) {
				cout << "IMPOSSIBLE" << endl;
				return 0;
			}
		}
	}
	fori(i, 0, n)
		cout << col[i] + 1 << " ";
	cout << endl;
	