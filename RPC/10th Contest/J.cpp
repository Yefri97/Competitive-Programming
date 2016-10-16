/*
 *  RPC 10-th Contest 2016
 *  Problem J: Progressions
 *  Status: Accepted
 */

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MAX_N = 1000;

int maxAreaHist(int hist[], int n) {
  int maxArea = 0;
  stack<int> s; s.push(0);
  for (int i = 1; i < n; i++) {
    while (hist[i] < hist[s.top()]) {
      int t = s.top(); s.pop();
      int area = hist[t] * (i - s.top() - 1);
      maxArea = max(maxArea, area);
    }
    s.push(i);
  }
  return maxArea;
}

int maxAreaMat(int mat[][MAX_N + 10], int n, int m) {
  int ans = 0;
  int row[MAX_N + 10]; memset(row, 0, sizeof row);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (mat[i][j] || mat[i][j + 1]) {
        if (i > 0 && row[j + 1] == 0) row[j + 1]++;
        row[j + 1]++;
      } else {
        row[j + 1] = 0;
      }
    }
    ans = max(ans, maxAreaHist(row, m + 2));
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int n, m;
  while (cin >> n >> m) {
    int board[MAX_N + 10][MAX_N + 10];
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        cin >> board[i][j];
    int mat[MAX_N + 10][MAX_N + 10]; memset(mat, 0, sizeof mat);
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
      int a = 1, b = 1, c = 1;
      if (i > 0) a = (board[i][j] == board[i - 1][j] + 1);
      if (j > 0) b = (board[i][j] == board[i][j - 1] + 1);
      if (i > 0 && j > 0) c = (board[i][j] == board[i - 1][j - 1] + 2);
      mat[i][j] = (a && b && c);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int cont = 1;
      for (int j = 1; j < m; j++) {
        if (board[i][j] == board[i][j - 1] + 1) cont++;
        else {
          ans = max(ans, cont);
          cont = 1;
        }
      }
      ans = max(ans, cont);
    }
    for (int j = 0; j < m; j++) {
      int cont = 1;
      for (int i = 1; i < n; i++) {
        if (board[i][j] == board[i - 1][j] + 1) cont++;
        else {
          ans = max(ans, cont);
          cont = 1;
        }
      }
      ans = max(ans, cont);
    }
    ans = max(ans, maxAreaMat(mat, n, m));
    cout << ans << endl;
  }
  return 0;
}