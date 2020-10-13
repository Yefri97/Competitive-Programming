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
	queue<int> q; q.push(0);
	vi par(n, -1); par[0] = 0;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int v : g[u]) if (par[v] == -1) {
			par[v] = u;
			q.push(v);
		}
	}
	if (par[n - 1] == -1) {
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}
	vi ans;
	int u = n - 1;
	while (u != 0) {
		ans.push_back(u);
		u = par[u];
	}
	ans.push_back(0);
	reverse(all(ans));
	cout << SZ(ans) << endl;
	for (int x : ans)
		cout << x + 1 << " ";
	cout << endl;
	return 0;
}
