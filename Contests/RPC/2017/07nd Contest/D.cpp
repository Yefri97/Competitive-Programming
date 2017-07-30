#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int INF = 1e9, MAXN = 110;

int n, m;
vii g[MAXN];
map<string, int> mapper;

ll solver() {
	vi d(n + 1, INF); d[0] = 0;
	queue<int> q; q.push(0);
	ll ans = 0;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		fori(i, 0, g[u].size()) {
			ii v = g[u][i];
			if (d[v.first] == INF) {
				d[v.first] = d[u] + 1;
				ans += v.second;
				q.push(v.first);
			}
		}
	}
	fori(i, 0, n + 1)
		if (d[i] == INF)
			ans = -1;
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	mapper["English"] = 0;
	fori(i, 0, n) {
		string name; cin >> name;
		mapper[name] = i + 1;
	}
	fori(i, 0, m) {
		string a, b; cin >> a >> b;
		ll cost; cin >> cost;
		g[mapper[a]].push_back(ii(mapper[b], cost));
		g[mapper[b]].push_back(ii(mapper[a], cost));
	}
	fori(i, 0, n + 1)
		sort(g[i].begin(), g[i].end());
	ll ans = solver();
	if (ans == -1)
		cout << "Impossible" << endl;
	else
		cout << ans << endl;
	return 0;
}