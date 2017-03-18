// APSP + DP
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100, MAXK = 5000, INF = 1e9;
int n, k, source[MAXK + 10], target[MAXK + 10];
int AdjMat[MAXN + 10][MAXN + 10], memo[MAXK + 10][MAXN + 10][5];

int solver(int id, int curr, int h) {
	if (id == k) {
		if (h == 0) return 0;
		if (h == 1) return AdjMat[curr][target[k-1]];
		if (h == 2) return AdjMat[curr][target[k-2]] + AdjMat[target[k-2]][target[k-1]];
	}
	if (memo[id][curr][h] != -1) return memo[id][curr][h];
	int ans;
	if (h == 0) ans = solver(id + 1, source[id], 1) + AdjMat[curr][source[id]];
	if (h == 2) ans = solver(id, target[id-2], 1) + AdjMat[curr][target[id-2]];
	if (h == 1) ans = min(solver(id+1, source[id], 2) + AdjMat[curr][source[id]], 
												solver(id, target[id-1], 0) + AdjMat[curr][target[id-1]]);
	return memo[id][curr][h] = ans;
}

void floyd_warshall() {
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				AdjMat[i][j] = min(AdjMat[i][j], AdjMat[i][k] + AdjMat[k][j]);
}

int main() {
	int t, cs = 1; cin >> t;
	while (t--) {
		int m; cin >> n >> m >> k;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				AdjMat[i][j] = INF;
		while (m--) {
			int a, b, w; cin >> a >> b >> w; a--; b--;
			AdjMat[a][b] = min(AdjMat[a][b], w);
			AdjMat[b][a] = min(AdjMat[b][a], w);
		}
		floyd_warshall();
		for (int i = 0; i < n; i++) AdjMat[i][i] = 0;
		for (int i = 0; i < k; i++) {
			int a, b; cin >> a >> b; a--; b--;
			source[i] = a;
			target[i] = b;
		}
		memset(memo, -1, sizeof memo);
		int ans = 0;
		for (int i = 0; i < k; i++)
			if (AdjMat[source[i]][target[i]] == INF)
				ans = -1;
		if (ans != -1) ans = solver(0, 0, 0);
		cout << "Case #" << cs++ << ": " << ans << endl;
	}
	return 0;
}