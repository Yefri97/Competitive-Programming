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

int color[mxn], wb[2];
vi g[mxn];

bool bgc(int s) {
	queue<int> q; q.push(s);
	color[s] = 0;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		wb[color[u]]++;
		fori(i, 0, g[u].size()) {
			int v = g[u][i];
			if (color[v] == -1) {
				color[v] = 1 - color[u];
				q.push(v);
			} else if (color[v] == color[u]) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		fori(i, 0, n) g[i].clear();
		while (m--) {
			int a, b; cin >> a >> b;
			g[a].push_back(b);
			g[b].push_back(a);
		}
		int ans = 0;
		bool isBipartite = true;
		memset(color, -1, sizeof color);
		fori(u, 0, n) {
			if (color[u] == -1) {
				wb[0] = wb[1] = 0;
				isBipartite &= bgc(u);
				ans += (wb[0] + wb[1] == 1 ? 1 : min(wb[0], wb[1]));
			}
		}
		cout << (isBipartite ? ans : -1) << endl;
	}
	return 0;
}