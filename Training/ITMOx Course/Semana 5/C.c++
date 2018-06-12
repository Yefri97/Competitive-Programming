/*
 *  ITMOx Course - 4st Week Problems
 *  Problem: Shortest Paths and Their Friends
 *  Level: Easy
 */
#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl;
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, ll> ii;
typedef vector<ii> vii;

const ll INF = 2e18;

int n;
vector<vii> g;
vector<ll> dist;
vector<bool> neg;

void dfs(int u) {
	neg[u] = true;
	for (int i = 0; i < g[u].size(); i++) {
		ii v = g[u][i];
		if (!neg[v.first])
			dfs(v.first);
	}
}

void bellmanFord(int s) {
	dist.assign(n, INF); dist[s] = 0;

	for (int i = 0; i < n - 1; i++) {
		for (int u = 0; u < n; u++) {
			if (dist[u] == INF) continue;
			for (int j = 0; j < g[u].size(); j++) {
				ii v = g[u][j];
				if (dist[v.first] > dist[u] + v.second)
					dist[v.first] = max(-INF, dist[u] + v.second);
			}
		}
	}

	neg.assign(n, false);
	for (int u = 0; u < n; u++)
		for (int i = 0; i < g[u].size(); i++) {
			ii v = g[u][i];
			if (!neg[v.first] && dist[u] < INF && dist[v.first] > dist[u] + v.second)
				dfs(v.first);
		}
}

int main() {
	ios::sync_with_stdio(false);  // Fast input - output
	ifstream fin("input.txt");    // File Input
	ofstream fout("output.txt");  // File Output
	/*** Code ***/
	int m, s; fin >> n >> m >> s; s--;
	g.assign(n, vii());
	for (int i = 0; i < m; i++) {
		int a, b; fin >> a >> b; a--; b--;
		ll w; fin >> w;
		g[a].push_back(ii(b, w));
	}

	bellmanFord(s);

	for (int u = 0; u < n; u++) {
		if (neg[u])
			fout << "-" << endl;
		else if (dist[u] == INF)
			fout << "*" << endl;
		else
			fout << dist[u] << endl;
	}
	return 0;
}