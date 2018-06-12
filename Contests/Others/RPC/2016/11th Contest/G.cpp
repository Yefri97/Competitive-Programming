/*
 *  RPC 11-th Contest 2016
 *  Problem G: Go--
 *  Status: Accepted
 */

#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 500;
int black[MAX_N + 10][MAX_N + 10], white[MAX_N + 10][MAX_N + 10];

int main() {
  int n, p;
  while (cin >> n >> p) {
    
    memset(black, 0, sizeof black);
    for (int i = 0; i < p; i++) {
      int x, y; cin >> x >> y; x--; y--;
      black[x][y] = 1;
    }
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
      if (i > 0) black[i][j] += black[i - 1][j];
      if (j > 0) black[i][j] += black[i][j - 1];
      if (i > 0 && j > 0) black[i][j] -= black[i - 1][j - 1];
    }

    memset(white, 0, sizeof white);
    for (int i = 0; i < p; i++) {
      int x, y; cin >> x >> y; x--; y--;
      white[x][y] = 1;
    }
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
      if (i > 0) white[i][j] += white[i - 1][j];
      if (j > 0) white[i][j] += white[i][j - 1];
      if (i > 0 && j > 0) white[i][j] -= white[i - 1][j - 1];
    }

    int b = 0, w = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        for (int k = 0; i + k < n && j + k < n; k++) {
          int bs = black[i + k][j + k];
          if (i > 0) bs -= black[i - 1][j + k];
          if (j > 0) bs -= black[i + k][j - 1];
          if (i > 0 && j > 0) bs += black[i - 1][j - 1];

          int ws = white[i + k][j + k];
          if (i > 0) ws -= white[i - 1][j + k];
          if (j > 0) ws -= white[i + k][j - 1];
          if (i > 0 && j > 0) ws += white[i - 1][j - 1];

          if (bs > 0 && ws == 0) b++;
          if (ws > 0 && bs == 0) w++;
          if (bs > 0 && ws > 0) break;
        }
      }
    }
    cout << b << " " << w << endl;
  }
  return 0;
}