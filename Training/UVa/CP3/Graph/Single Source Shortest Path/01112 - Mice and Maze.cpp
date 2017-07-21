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

void sssp(int s) {
	dist.assign(n, oo); dist[s] = 0;
	priority_queue<ii, vector<ii>, greater<ii> > pq; pq.push(ii(0, s));
	while (!pq.empty()) {
		ii front = pq.top(); pq.pop();
		int d = front.first, u = front.second;
		if (d > dist[u]) continue;
		fori(i, 0, g[u].size()) {
			ii v = g[u][i];
			if (dist[u] + v.second < dist[v.first]) {
				dist[v.first] = dist[u] + v.second;
				pq.push(ii(dist[v.first], v.first));
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int ex, mt; cin >> n >> ex >> mt; ex--;
		fori(i, 0, n) g[i].clear();
		int m; cin >> m;
		while (m--) {
			int a, b, w; cin >> a >> b >> w; a--; b--;
			g[b].push_back(ii(a, w));
		}
		sssp(ex);
		int ans = 0;
		fori(i, 0, n)
			ans += (mt >= dist[i]);
		cout << ans << endl;
		if (t) cout << endl;
	}
	return 0;
}