/*
 *  ITMOx Course - 4st Week Problems
 *  Problem: Bipartite Graph
 *  Level: Easy
 */
#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl;
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

vector<vi> g;
vi color;

bool bipartiteCheck(int u, int c) {
	color[u] = c;
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		if (color[v] == -1) {
			if (!bipartiteCheck(v, 1 - c)) return false;
		} else if (color[v] == c) {
			return false;
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);  // Fast input - output
	ifstream fin("input.txt");    // File Input
	ofstream fout("output.txt");  // File Output
	/*** Code ***/
	int n, m; fin >> n >> m;
	g.assign(n, vi());
	for (int i = 0; i < m; i++) {
		int a, b; fin >> a >> b; a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	color.assign(n, -1);
	bool ans = true;
	for (int u = 0; u < n and ans; u++) {
		if (color[u] == -1)
			ans = bipartiteCheck(u, 0);
	}
	fout << ((ans)? "YES" : "NO") << endl;
	return 0;
}