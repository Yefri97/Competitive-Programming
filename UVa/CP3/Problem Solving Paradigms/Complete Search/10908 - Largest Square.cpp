#include <bits/stdc++.h>

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n, m, q; cin >> n >> m >> q;
		char board[110][110];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> board[i][j];
		cout << n << " " << m << " " << q << endl;
		while (q--) {
			int r, c, ans = 1; cin >> r >> c;
			char ch = board[r][c];
			for (int k = 1, ok = 1; r - k >= 0 && c - k >= 0 && r + k < n && c + k < m; k++) {
				for (int i = r - k; i <= r + k; i++)
					for (int j = c - k; j <= c + k; j++)
						if (ch != board[i][j]) ok = 0;
				if (!ok) break;
				ans += 2;
			}
			cout << ans << endl;
		}
	}
	return 0;
}