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

const int oo = 1e9, mxn = 200;

int cc;
int visited[mxn];
vi g[mxn];

void dfs(int u) {
	visited[u] = 1;
	fori(i, 0, g[u].size()) {
		int v = g[u][i];
		if (!visited[v])
			dfs(v);
		cc++;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, m;
	while (cin >> n >> m) {
		fori(i, 0, n) g[i].clear();
		vi deg(n);
		fori(i, 0, m) {
			int u, v; cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
			deg[u]++;
			deg[v]++;
		}
		int b = 1;
		fori(i, 0, n)
			b &= ((deg[i] % 2) == 0);
		cc = 0;
		memset(visited, 0, sizeof visited);
		fori(i, 0, n) if (deg[i]) {
			dfs(i);
			break;
		}
		if (!b || cc == 0 || cc != 2 * m) cout << "Not ";
		cout << "Possible" << endl;
	}
	return 0;
}