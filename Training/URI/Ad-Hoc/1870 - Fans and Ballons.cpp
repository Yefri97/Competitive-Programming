#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 10;
int board[MAX_N + 10][MAX_N + 10];

int main() {
  int n, m, p;
  while (cin >> n >> m >> p && (n + m + p)) {
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
      cin >> board[i][j];
    int i = 0, j = p - 1, live = 1;
    while (live && i < n) {
      int a, b; a = b = j;
      while (board[i][a] == 0) a--;
      while (board[i][b] == 0) b++;
      int diff = board[i][a] - board[i][b], x = abs(diff);
      while (live && x--) {
        j += (diff < 0)? -1 : 1;
        if (board[i][j] != 0) live = 0;
      }
      i++;
    }
    if (live) cout << "OUT " << j + 1 << endl;
    else cout << "BOOM " << i << " " << j + 1 << endl;
  }
  return 0;
}