/*
 *  RPC 11-th Contest 2016
 *  Problem L: Tiles
 *  Status: Accepted
 */

#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 200, VISITED = -1;
int n, m, board[MAX_N + 10][MAX_N + 10];

int mi[10] = {-1, 0, 1, 0};
int mj[10] = {0, 1, 0, -1};

int floodfill(int ui, int uj, int color) {
  if (ui < 0 || ui >= n || uj < 0 || uj >= m) return 0;
  if (board[ui][uj] != color) return 0;
  int ans = 1;
  board[ui][uj] = VISITED;
  for (int i = 0; i < 4; i++)
    ans += floodfill(ui + mi[i], uj + mj[i], color);
  return ans;
}

int main() {
  while (cin >> n >> m) {
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        cin >> board[i][j];
    int target = n * m;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
      if (board[i][j] != VISITED) 
        target = min(target, floodfill(i, j, board[i][j]));
    }
    cout << target << endl;
  }
  return 0;
}