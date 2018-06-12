/*
 *  ITMOx Course - 4st Week Problems
 *  Problem: Find a Cycle
 *  Level: Easy
 */
#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl;
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

#define DFS_WHITE -1
#define DFS_GRAY 0
#define DFS_BLACK 1

vector<vi> g;

ii backEdge;
vi dfs_num, dfs_parent;

bool cycleCheck(int u) {
	dfs_num[u] = DFS_GRAY;
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		if (dfs_num[v] == DFS_WHITE) {
			dfs_parent[v] = u;
			if (cycleCheck(v)) return true;
		} else if (dfs_num[v] == DFS_GRAY) {
			backEdge = ii(u, v);
			return true;
		}
	}
	dfs_num[u] = DFS_BLACK;
	return false;
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
	}
	dfs_parent.assign(n, -1);
	dfs_num.assign(n, DFS_WHITE);
	bool ans = false;
	for (int i = 0; i < n and !ans; i++) {
		if (dfs_num[i] == DFS_WHITE)
			ans = cycleCheck(i);
	}
	if (ans) {
		fout << "YES" << endl;
		stack<int> st;
		for (int u = backEdge.first; u != backEdge.second; u = dfs_parent[u])
			st.push(u + 1);
		st.push(backEdge.second + 1);
		while (!st.empty())
			fout << st.top() << " ", st.pop();
		fout << endl;
	} else {
		fout << "NO" << endl;
	}
	return 0;
}