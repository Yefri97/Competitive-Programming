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

const int oo = 1e9, mxn = 100010;

vi cnt, color, g[mxn];

void colorBipartite(int u, int c) {
	cnt[c]++;
	color[u] = c;
	fori(i, 0, g[u].size()) {
		int v = g[u][i];
		if (color[v] == -1)
			colorBipartite(v, 1 - c);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	fori(i, 0, n - 1) {
		int u, v; cin >> u >> v; u--; v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	cnt.assign(2, 0);
	color.assign(n, -1);
	colorBipartite(0, 0);
	ll ans = 0;
	fori(i, 0, n)
		ans += (cnt[1 - color[i]] - (int)(g[i].size()));
	cout << ans / 2 << endl;
	return 0;
}