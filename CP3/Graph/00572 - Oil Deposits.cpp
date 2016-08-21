#include <bits/stdc++.h>

using namespace std;

int m, n;
char board[110][110];

int mi[10] = {1, 1, 0, -1, -1, -1, 0, 1};
int mj[10] = {0, 1, 1, 1, 0, -1, -1, -1};

void flood_fill(int io, int jo) {
	board[io][jo] = '+';
	for (int d = 0; d < 8; d++) {
		int i = io + mi[d], j = jo + mj[d];
		if (i < 0 || i >= m || j < 0 || j >= n) continue;
		if (board[i][j] == '@') flood_fill(i, j);
	}
}

int main() {
	while (cin >> m >> n && m + n) {
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				cin >> board[i][j];
		int ans = 0;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				if (board[i][j] == '@') {
					flood_fill(i, j);
					ans++;
				}
		cout << ans << endl;
	}
	return 0;
}