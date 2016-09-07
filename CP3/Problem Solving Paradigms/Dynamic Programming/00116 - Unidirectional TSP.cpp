#include <bits/stdc++.h>
using namespace std;

const int MN = 100, INF = 1e9, mi[5] = {-1, 0, 1};
int n, m, path[MN + 10][MN + 10], board[MN + 10][MN + 10], memo[MN + 10][MN + 10];

int mod(int n, int m) { return (n % m + m) % m; }

int minPath(int i, int j) {
  if (j == m - 1) return 0;
  if (memo[i][j] != -1) return memo[i][j];
  int ans = INF;
  for (int k = 0; k < 3; k++) {
    int v = mod(i + mi[k], n), x = minPath(v, j + 1) + board[v][j + 1];
    if (x < ans) {
      path[i][j] = v;
      ans = x;
    } else if (x == ans) 
      path[i][j] = min(path[i][j], v);
  }
  return memo[i][j] = ans;
}

int main() {
  while (cin >> n >> m) {
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        cin >> board[i][j];
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        path[i][j] = MN;
    memset(memo, -1, sizeof memo);
    int ans = INF, init = -1;
    for (int i = 0; i < n; i++) {
      int x = minPath(i, 0) + board[i][0];
      if (x < ans) {
        init = i;
        ans = x;
      }
    }
    for (int i = init, j = 0; j < m; j++) {
      if (j) cout << " ";
      cout << i + 1;
      i = path[i][j];
    }
    cout << endl;
    cout << ans << endl;
  }
  return 0;
}