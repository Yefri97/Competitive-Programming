#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100;
int board[MAX_N + 10][MAX_N + 10];

int mi[10] = {-1, -1, -1, 0, 1, 1, 1, 0};
int mj[10] = {-1, 0, 1, 1, 1, 0, -1, -1};

int main() {
  int cs = 0;
  int n, m;
  while (cin >> n >> m && (n + m)) {
    if (cs) cout << endl;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
      char c; cin >> c;
      if (c == '*') board[i][j] = -1;
      else board[i][j] = 0;
    }

    for (int ui = 0; ui < n; ui++) for (int uj = 0; uj < m; uj++) {
      int c = board[ui][uj];
      if (c == -1) {
        for (int i = 0; i < 8; i++) {
          int vi = ui + mi[i], vj = uj + mj[i];
          if (vi < 0 || vi >= n || vj < 0 || vj >= m) continue;
          if (board[vi][vj] == -1) continue;
          board[vi][vj]++;
        }
      }
    }

    cout << "Field #" << ++cs << ":" << endl;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++)
        if (board[i][j] == -1) cout << "*";
        else cout << board[i][j];
      cout << endl;
    }

  }
  return 0;
}