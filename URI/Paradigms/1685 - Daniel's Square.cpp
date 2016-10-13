#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1000;
char board[MAX_N + 10][MAX_N + 10];
int mat[MAX_N + 10][MAX_N + 10];

int main() {
  int t; cin >> t;
  while (t--) {
    int n, m; cin >> n >> m;
    int mmax = 0;
    memset(mat, 0, sizeof mat);
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
      cin >> board[i][j];
    }
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
      if (board[i][j] == '.') mat[i][j] = min(mat[i - 1][j], mat[i][j - 1]) + 1;
      mmax = max(mmax, mat[i][j]);
    }
    cout << "The side of the square is " << mmax << " and the locations are:" << endl;
    int cont = 0;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
      if (mat[i][j] == mmax) {
        cout << i - (mmax - 1) << " " << j - (mmax - 1) << endl;
        cont++;
      }
    }
    cout << cont << " in total." << endl;
  }
  return 0;
}