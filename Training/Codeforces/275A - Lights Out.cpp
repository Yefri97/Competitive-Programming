#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3;
int mat[MAXN + 10][MAXN + 10], board[MAXN + 10][MAXN + 10];

int mi[] = {-1, 0, 1, 0, 0};
int mj[] = {0, 1, 0, -1, 0};

int main() {
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			cin >> board[i][j];
	memset(mat, 0, sizeof mat);
	for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) {
		for (int k = 0; k < 5; k++) {
			int ui = i + mi[k], uj = j + mj[k];
			if (ui < 0 || ui >= 3 || uj < 0 || uj >= 3) continue;
			mat[ui][uj] += board[i][j];
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) cout << ((mat[i][j] % 2) == 0);
		cout << endl;
	}
	return 0;
}