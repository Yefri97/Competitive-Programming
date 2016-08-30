/*
 *  RPC 9-th Contest 2016
 *  Problem G: Pac Man for your New Phone
 *  Status: Accepted
 */

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100, INF = 1e8;
int n, m, board[MAXN + 10][MAXN + 10], memo[MAXN + 10][MAXN + 10];

int pacman(int i, int j) {
  if (i == n - 1 && j == m - 1) return 0;
  if (i >= n || j >= m) return -INF;
  if (memo[i][j] != -1) return memo[i][j];
  return memo[i][j] = max(pacman(i + 1, j) + board[i + 1][j], pacman(i, j + 1) + board[i][j + 1]);
}

int main() {
  int t; cin >> t;
  int cs = 0;
  while (t--) {
    cout << "Game Board #" << ++cs << ": ";
    memset(memo, -1, sizeof memo);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if ((i == 0 && j == 0) || (i == n - 1 && j == m - 1)) {
          char c; cin >> c;
          board[i][j] = 0;
        } else {
          cin >> board[i][j];
        }
    int ans = pacman(0, 0);
    cout << ans << endl;
  }  
  return 0;
}