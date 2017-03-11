/*
 *  HackerRank - Warmup Challenges
 *  Problem: Diagonal Difference
 *  Level: Easy
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  int mat[n + 10][n + 10];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> mat[i][j];
  int x = 0, y = 0;
  for (int i = 0; i < n; i++)
    x += mat[i][i];
  for (int i = 0; i < n; i++)
    y += mat[i][n - i - 1];
  int ans = abs(x - y);
  cout << ans << endl;
  return 0;
}