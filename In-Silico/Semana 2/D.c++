/*
 *  ITMOx Course - 1st Week Problems
 *  Problem: Create a Team!
 *  Level: Easy
 */
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

double score(double a, double b, double c) { return sqrt(a * a + b * b + c * c); }

int main() {
  ios::sync_with_stdio(false);  // Fast input - output
  ifstream fin("input.txt");    // File Input
  ofstream fout("output.txt");  // File Output
  /*** Code ***/
  int board[3][3];
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      fin >> board[i][j];
  double ans = 0.0;
  ans = max(ans, score(board[0][0], board[1][1], board[2][2]));
  ans = max(ans, score(board[0][0], board[1][2], board[2][1]));
  ans = max(ans, score(board[0][1], board[1][0], board[2][2]));
  ans = max(ans, score(board[0][1], board[1][2], board[2][0]));
  ans = max(ans, score(board[0][2], board[1][0], board[2][1]));
  ans = max(ans, score(board[0][2], board[1][1], board[2][0]));
  fout << fixed << ans << endl;
  return 0;
}