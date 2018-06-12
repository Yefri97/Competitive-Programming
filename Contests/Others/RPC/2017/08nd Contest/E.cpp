#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))
#define sq(x) (x) * (x)

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

const int oo = 2e9, mxn = 10010;

int n;
vii g[mxn];

ll sssp(int s, int t, ll cap) {
	vi dist(n, 1e16); dist[s] = 0;
	priority_queue<ii, vector<ii>, greater<ii> > pq; pq.push(ii(0, s));
	while (!pq.empty()) {
		ii front = pq.top(); pq.pop();
		ll u = front.second, w = front.first;
		if (u == t) return dist[t];
		if (w > dist[u]) continue;
		fori(i, 0, g[u].size()) {
			ii v = g[u][i];
			if (v.second > cap) continue;
			if (dist[u] + v.second < dist[v.first]) {
				dist[v.first] = dist[u] + v.second;
				pq.push(ii(dist[v.first], v.first));
			}
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll m, p; cin >> n >> m >> p;
	while (m--) {
		ll u, v, t; cin >> u >> v >> t; u--; v--;
		g[u].push_back(ii(v, t));
		g[v].push_back(ii(u, t));
	}
	ll x = sssp(0, n - 1, oo);
	ll low = 0, high = oo;
	while (high - low > 1) {
		ll mid = (high + low) * 0.5;
		ll y = sssp(0, n - 1, mid);
		if (y != -1 && y * 100 <= x * (100 + p))
			high = mid;
		else
			low = mid;
	}
	cout << high << endl;
	return 0;
}