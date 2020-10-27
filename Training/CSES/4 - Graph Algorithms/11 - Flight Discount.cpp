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
typedef pair<ll, int> ii;

const ll oo = 1e16;
const int MN = 2e5 + 10;

int n, m;
vi g[MN];
int from[MN], to[MN];
ll cost[MN];

vector<ll> dijkstra(int inv, int s) {
	priority_queue<ii> pq; pq.push(ii(0, s));
	vector<ll> dist(n, oo); dist[s] = 0;
	while (!pq.empty()) {
		ii top = pq.top(); pq.pop();
		int u = top.second;
		ll d = -top.first;
		if (d > dist[u]) continue;
		for (int e : g[u]) {
			int v = inv ? from[e] : to[e];
			if (dist[v] > dist[u] + cost[e]) {
				dist[v] = dist[u] + cost[e];
				pq.push(ii(-dist[v], v));
			}
		}
	}
	return dist;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef UTP
	freopen("input.txt", "r", stdin);
	#endif
	cin >> n >> m;
	fori(i, 0, m) {
		cin >> from[i]; from[i]--;
		cin >> to[i]; to[i]--;
		cin >> cost[i];
		g[from[i]].push_back(i);
		g[to[i]].push_back(i);
	}
	vector<ll> dist_a = dijkstra(0, 0);
	vector<ll> dist_b = dijkstra(1, n - 1);
	ll ans = oo;
	fori(i, 0, m) {
		ll c = dist_a[from[i]] + dist_b[to[i]];
		ans = min(ans, c + cost[i] / 2);
	}
	cout << ans << endl;
	return 0;
}
