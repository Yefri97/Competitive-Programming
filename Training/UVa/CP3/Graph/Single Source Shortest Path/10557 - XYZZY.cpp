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

const int oo = 1e9, mxn = 110;

int n;
vi dist;
vii g[mxn];
vector<bool> neg;

void dfs(int u) {
	neg[u] = true;
	fori(i, 0, g[u].size()) {
		ii v = g[u][i];
		if (!neg[v.first])
			dfs(v.first);
	}
}

void bellmand_ford(int s) {
	dist.assign(n, -1); dist[s] = 100;

	fori(i, 0, n - 1) {
		fori(u, 0, n) {
			if (dist[u] == -1) continue;
			fori(j, 0, g[u].size()) {
				ii v = g[u][j];
				if (dist[u] + v.second <= 0) continue;
				dist[v.first] = max(dist[v.first], dist[u] + v.second);
			}
		}
	}

	neg.assign(n, false);
	fori(u, 0, n) {
		if (dist[u] == -1) continue;
		fori(j, 0, g[u].size()) {
			ii v = g[u][j];
			if (dist[u] + v.second <= 0) continue;
			if (!neg[v.first] && dist[u] + v.second > dist[v.first])
				dfs(v.first);
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	while (cin >> n && n != -1) {
		fori(i, 0, n) g[i].clear();
		vi power(n);
		fori(u, 0, n) {
			cin >> power[u];
			int m; cin >> m;
			while (m--) {
				int v; cin >> v; v--;
				g[u].push_back(ii(v, -1));
			}
		}
		fori(u, 0, n)
			fori(j, 0, g[u].size())
				g[u][j].second = power[g[u][j].first];
		
		bellmand_ford(0);

		cout << (dist[n - 1] != -1 || neg[n - 1] == true ? "winnable" : "hopeless") << endl;

	}
	return 0;
}