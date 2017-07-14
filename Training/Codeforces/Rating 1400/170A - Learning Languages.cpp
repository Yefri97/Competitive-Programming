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

const int oo = 1e9, mxn = 210;

vi g[mxn];
vector<bool> visited;

void dfs(int u) {
	visited[u] = true;
	fori(i, 0, g[u].size()) {
		int v = g[u][i];
		if (!visited[v])
			dfs(v);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, m; cin >> n >> m;
	fori(i, 0, n) {
		int k; cin >> k;
		fori(j, 0, k) {
			int x; cin >> x; x--;
			g[i].push_back(n + x);
			g[n + x].push_back(i);
		}
	}
	visited.assign(n + m, false);
	int ans = 0;
	fori(i, 0, n) {
		if (!visited[i]) {
			dfs(i);
			ans++;
		}
	}
	int flag = 0;
	fori(i, 0, m)
		if (visited[n + i])
			flag = 1;
	cout << ans - flag << endl;
	return 0;
}