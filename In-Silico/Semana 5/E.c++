/*
 *  ITMOx Course - 4st Week Problems
 *  Problem: Shortest Path in a Dense Graph
 *  Level: Easy
 */
#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl;
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const ll INF = 1e15;

int V, t;
vector<vii> g;
vector<ll> dist;

void dijkstra(int s) {
	dist.assign(V, INF); dist[s] = 0;
	priority_queue<ii, vector<ii>, greater<ii> > pq; pq.push(ii(0, s));
	while (!pq.empty()) {
		ii front = pq.top(); pq.pop();
		int d = front.first, u = front.second;
		if (u == t) return;
		if (d > dist[u]) continue;
		for (int i = 0; i < g[u].size(); i++) {
			ii v = g[u][i];
			if (dist[v.first] > dist[u] + v.second) {
				dist[v.first] = dist[u] + v.second;
				pq.push(ii(dist[v.first], v.first));
			}
		}
	}
}

int main() {
  ios::sync_with_stdio(false);  // Fast input - output
  ifstream fin("input.txt");    // File Input
  ofstream fout("output.txt");  // File Output
  /*** Code ***/
  int n, s; fin >> n >> s >> t; s--; t--;
  g.assign(n, vii());
  for (int u = 0; u < n; u++) {
  	for (int v = 0; v < n; v++) {
  		int w; fin >> w;
  		if (u == v || w < 0) continue;
  		g[u].push_back(ii(v, w));
  	}
  }

  V = n;
	dijkstra(s);

	fout << ((dist[t] == INF) ? -1 : dist[t]) << endl;

  return 0;
}