#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9, MN = 100000;

int n, m;
int cnt, nComps, compOf[MN];
int low[MN], num[MN], vis[MN];
stack<int> st;
vi g[MN], g2[MN];

void scc(int u) {
	low[u] = num[u] = cnt++;
	st.push(u);
	vis[u] = 1;
	for (int v : g[u]) {
		if (num[v] == -1)
			scc(v);
		if (vis[v])
			low[u] = min(low[u], low[v]);
	}
	if (low[u] == num[u]) {
		while (true) {
			int v = st.top(); st.pop();
			vis[v] = 0;
			compOf[v] = nComps;
			if (u == v) break;
		}
		nComps++;
	}
}

void condense() {
	memset(num, -1, sizeof num);
	fori(i, 0, n) if (num[i] == -1)
		scc(i);
	fori(u, 0, n)
		for (int v : g[u]) if (compOf[u] != compOf[v])
			g2[compOf[u]].push_back(compOf[v]);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	int k; cin >> k; k--;
	fori(i, 0, m) {
		int u, v; cin >> u >> v; u--; v--;
		g[u].push_back(v);
	}
	condense();
	vi in(nComps);
	fori(u, 0, nComps)
		for (int v : g2[u])
			in[v] = 1;
	int ans = 0;
	fori(i, 0, nComps) if (i != compOf[k])
		ans += (in[i] == 0);
	cout << ans << endl;
	return 0;
}
