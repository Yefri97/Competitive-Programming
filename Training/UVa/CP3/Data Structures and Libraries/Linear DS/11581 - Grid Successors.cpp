// 2D Array Manipulation
#include <bits/stdc++.h>
using namespace std;

const int n = 3;
char mat[n + 10][n + 10], buff[n + 10][n + 10];
int mi[] = {0, -1, 0, 1};
int mj[] = {-1, 0, 1, 0};

bool check() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (mat[i][j] != '0') return false;
	return true;
}

int main() {
	int t; cin >> t;
	while (t--) {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> mat[i][j];
		int ans = 0;
		while (!check()) {
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					buff[i][j] = mat[i][j];
			for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
				int acc = 0;
				for (int k = 0; k < 4; k++) {
					int vi = i + mi[k], vj = j + mj[k];
					if (vi < 0 || vi >= n || vj < 0 || vj >= n) continue;
					acc += buff[vi][vj] - '0';
				}
				mat[i][j] = (acc % 2) + '0';
			}
			ans++;
		}
		cout << ans - 1 << endl;
	}
	return 0;
}