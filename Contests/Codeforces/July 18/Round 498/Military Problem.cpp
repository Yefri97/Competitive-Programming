#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define SZ(v) (int)v.size()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9, MN = 200010;

int seq[MN], pos[MN], len[MN], idx;
vi g[MN];

void dfs(int u) {
	int id = idx;
	seq[id] = u;
	pos[u] = idx++;
	for (int v : g[u])
		dfs(v);
	len[u] = idx - id;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, q; cin >> n >> q;
	fori(i, 1, n) {
		int p; cin >> p; p--;
		g[p].push_back(i);
	}
	idx = 0;
	dfs(0);
	while (q--) {
		int u, k; cin >> u >> k; u--;
		int ans = k - 1 < len[u] ? seq[pos[u] + k - 1] + 1 : -1;
		cout << ans << endl;
	}
	return 0;
}
