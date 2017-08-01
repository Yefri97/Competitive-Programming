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

const int oo = 1e9, mxn = 200000;

vi taken;
vii g[mxn];
priority_queue<ii, vector<ii>, greater<ii> > pq;

void process(int u) {
	taken[u] = 1;
	fori(i, 0, g[u].size()) {
		ii v = g[u][i];
		if (!taken[v.first]) pq.push(ii(v.second, v.first));
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, m;
	while (cin >> n >> m && n) {
		fori(i, 0, n) g[i].clear();
		int acc = 0;
		fori(i, 0, m) {
			int u, v, w; cin >> u >> v >> w;
			g[u].push_back(ii(v, w));
			g[v].push_back(ii(u, w));
			acc += w;
		}
		// Prims Algorithm
		taken.assign(n, 0);
		process(0);
		int mst_cost = 0;
		while (!pq.empty()) {
			ii front = pq.top(); pq.pop();
			int u = front.second, w = front.first;
			if (!taken[u])
				mst_cost += w, process(u);
		}
		cout << acc - mst_cost << endl;
	}
	return 0;
}