#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<ll, ll> ii;
typedef pair<ii, int> iii;

const ll oo = 2e10;
const int MN = 10010;

int in[MN];
ll dp[2][MN];
vector<iii> g[MN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int b, m; cin >> b >> m;
	int n = 0;
	map<string, int> mapper;
	fori(i, 0, m) {
		string a, b, c; cin >> a >> b >> c;
		int x, y; cin >> x >> y;
		if (mapper.count(a) == 0) mapper[a] = n++;
		if (mapper.count(b) == 0) mapper[b] = n++;
		int u = mapper[a];
		int v = mapper[b];
		g[v].push_back(iii(ii(x, y), u));
		in[u]++;
	}
	priority_queue< iii, vector<iii>, greater<iii> > pq;
	vector<ii> dist(n, ii(oo, -1));
	fori(i, 0, n) if (in[i] == 0) {
		pq.push(iii(ii(0, 0), i));
		dist[i] = ii(0, 0);
	}
	while (!pq.empty()) {
		iii front = pq.top(); pq.pop();
		ii d = front.first;
		int u = front.second;
		if (d > dist[u]) continue;
		for (iii v : g[u]) {
			ii nd = ii(d.first + v.first.first, d.second - v.first.second);
			if (nd < dist[v.second]) {
				dist[v.second] = nd;
				pq.push(iii(dist[v.second], v.second));
			}
		}
	}
	fori(i, 1, n + 1) {
		ll w = dist[i - 1].first, val = -dist[i - 1].second;
		fori(k, 0, b + 1) {
			dp[i % 2][k] = dp[(i - 1) % 2][k];
			if (k - w >= 0)
				dp[i % 2][k] = max(dp[i % 2][k], dp[(i - 1) % 2][k - w] + val);
		}
	}
	int ans = 0;
	fori(i, 1, b + 1) {
		if (dp[n % 2][i] > dp[n % 2][ans])
			ans = i;
	}
	cout << dp[n % 2][ans] << endl;
	cout << ans << endl;
	return 0;
}
