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

const ll oo = 1e15;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef UTP
	freopen("input.txt", "r", stdin);
	#endif
	int n, m; cin >> n >> m;
	vi g[n];
	vi from(m), to(m), cost(m);
	fori(i, 0, m) {
		cin >> from[i]; from[i]--;
		cin >> to[i]; to[i]--;
		cin >> cost[i];
		g[from[i]].push_back(i);
	}
	vector<ll> dist(n, oo); dist[0] = 0;
	priority_queue<ii> pq; pq.push(ii(0, 0));
	while (!pq.empty()) {
		ii top = pq.top(); pq.pop();
		int u = top.second, d = -top.first;
		if (d > dist[u]) continue;
		for (int e : g[u]) {
			int v = from[e] + to[e] - u;
			if (dist[v] > dist[u] + cost[e]) {
				dist[v] = dist[u] + cost[e];
				pq.push(ii(-dist[v], v));
			}
		}
	}
	fori(i, 0, n)
		cout << dist[i] << " ";
	cout << endl;
	return 0;
}
