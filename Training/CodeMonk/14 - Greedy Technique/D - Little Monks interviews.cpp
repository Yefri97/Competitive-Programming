#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl;
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int INF = 1e9;

int mst_prim(vector<vii> &AdjList, int V, int E) {
	vi taken(V);
	priority_queue<ii> pq; pq.push(ii(0, 0));
	int cost = 0;
	while (!pq.empty()) {
		ii front = pq.top(); pq.pop();
		int w = -front.first, u = front.second;
		if (!taken[u]) {
			cost += w;
			taken[u] = 1;
			fori(i, 0, AdjList[u].size()) {
				ii v = AdjList[u][i];
				if (!taken[v.first]) pq.push(ii(-v.second, v.first));
			}
		}
	}
	return cost;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int tc; cin >> tc;
  while (tc--) {
  	int n, m; cin >> n >> m;
  	vector<vii> g(n);
  	fori(i, 0, m) {
  		int a, b, w; cin >> a >> b >> w; a--; b--;
  		g[a].push_back(ii(b, -w));
  		g[b].push_back(ii(a, -w));
  	}
  	int ans = mst_prim(g, n, m);
  	cout << -ans << endl;
  }
  return 0;
}