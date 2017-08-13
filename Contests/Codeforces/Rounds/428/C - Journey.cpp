#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))
#define sq(x) (x) * (x)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int oo = 1e9, mxn = 100010;

vi g[mxn];
int visited[mxn];
double prob[mxn];

void dfs(int u, int l, double p) {
	int nc = g[u].size();
	if (u != 0) nc--;
	if (nc == 0) { prob[l] += p; return; }
	visited[u] = 1;
	fori(i, 0, g[u].size()) {
		int v = g[u][i];
		if (!visited[v])
			dfs(v, l + 1, p / nc);
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
	dfs(0, 0, 1.0);
	double ans = 0;
	fori(i, 0, n)
		ans += ((double)i * prob[i]);
	cout << fixed << setprecision(10) << ans << endl;
	return 0;
}