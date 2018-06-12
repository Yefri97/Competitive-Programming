/*
 *  ITMOx Course - 4st Week Problems
 *  Problem: Shortest Paths in a Sparse Graph
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

const int INF = 1e9;

int n;
vector<vii> g;
vi dist;

void dijkstra(int s) {
	dist.assign(n, INF); dist[s] = 0;
	priority_queue<ii, vector<ii>, greater<ii> > pq; pq.push(ii(0, s));
	while (!pq.empty()) {
		ii front = pq.top(); pq.pop();
		int d = front.first, u = front.second;
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
	int m; fin >> n >> m;
	g.assign(n, vii());
	for (int i = 0; i < m; i++) {
		int a, b, w; fin >> a >> b >> w; a--; b--;
		g[a].push_back(ii(b, w));
		g[b].push_back(ii(a, w));
	}

	dijkstra(0);

	for (int i = 0; i < n; i++)
		fout << dist[i] << " ";
	fout << endl;

	return 0;
}