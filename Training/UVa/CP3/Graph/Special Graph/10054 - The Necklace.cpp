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

const int oo = 1e9, mxn = 60;

int g[mxn][mxn], deg[mxn];
stack<int> ans;

void dfs(int u) {
	fori(i, 0, mxn) {
		if (g[u][i]) {
			g[u][i]--;
			g[i][u]--;
			dfs(i);
		}
	}
	ans.push(u);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t, cs = 0; cin >> t;
	while (t--) {
		memset(g, 0, sizeof g);
		memset(deg, 0, sizeof deg);
		int m; cin >> m;
		while (m--) {
			int u, v; cin >> u >> v; u--; v--;
			g[u][v]++; g[v][u]++;
			deg[u]++; deg[v]++;
		}
		bool b = true;
		fori(i, 0, mxn)
			b &= ((deg[i] % 2) == 0);
		cout << "Case #" << ++cs << endl;
		if (b) {
			fori(i, 0, mxn) if (deg[i]) {
				dfs(i);
				break;
			}
			while (ans.size() > 1) {
				int a = ans.top(); ans.pop();
				int b = ans.top();
				cout << a + 1 << " " << b + 1 << endl;
			}
			ans.pop();
		} else {
			cout << "some beads may be lost" << endl;
		}
		if (t) cout << endl;
	}
	return 0;
}