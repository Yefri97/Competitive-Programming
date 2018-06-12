#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9, MN = 1e5 + 10;

ll ans;
ll M[5][5];
int b[MN];
vi g[MN];

void dfs(int u, int p, int h) {
	for (int v : g[u]) {
		if (v == p) continue;
		dfs(v, u, 1 - h);
	}
	ans += M[h][1 - b[u]];
	ans += M[1 - h][b[u]];
	M[h][b[u]]++;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		memset(M, 0, sizeof M);
		int n; cin >> n;
		fori(i, 0, n) g[i].clear();
		fori(i, 0, n - 1) {
			int u, v; cin >> u >> v; u--; v--;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		fori(i, 0, n) {
			int x; cin >> x;
			int c = __builtin_popcount(x);
			b[i] = c & 1;
		}
		ans = 0;
		dfs(0, -1, 0);
		cout << ans << endl;
	}
	return 0;
}
