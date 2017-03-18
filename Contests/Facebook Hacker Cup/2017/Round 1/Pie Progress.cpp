// Dinamic Programming
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 300, INF = 1e9;
int n, m, board[MAXN + 10][MAXN + 10], memo[MAXN + 10][MAXN + 10];

int solver(int id, int curr) {
	if (curr == n) return 0;
	if (id == n || curr < id) return INF;
	if (memo[id][curr] != -1) return memo[id][curr];
	int cont = 1, cost = 0;
	int target = solver(id + 1, curr);
	for (int i = 0; i < m; i++) {
		cost += board[id][i];
		target = min(target, solver(id + 1, curr + cont) + cost + (cont * cont));
		cont++;
	}
	return memo[id][curr] = target;
}

int main() {
	int t, cs = 1; cin >> t;
	while (t--) {
		cin >> n >> m;
		memset(memo, -1, sizeof memo);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> board[i][j];
		for (int i = 0; i < n; i++)
			sort(board[i], board[i] + m);
		int ans = solver(0, 0);
		cout << "Case #" << cs++ << ": " << ans << endl;
	}
	return 0;
}