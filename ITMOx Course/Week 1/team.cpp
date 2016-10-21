#include <bits/stdc++.h>
using namespace std;

double score(double a, double b, double c) {
  return sqrt(a * a + b * b + c * c);
}

int main() {
  ifstream cin("team.in");
  ofstream cout("team.out");
  int mat[5][5];
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      cin >> mat[i][j];
  double ans = 0.0;
  ans = max(ans, score(mat[0][0], mat[1][1], mat[2][2]));
  ans = max(ans, score(mat[0][0], mat[1][2], mat[2][1]));
  ans = max(ans, score(mat[0][1], mat[1][0], mat[2][2]));
  ans = max(ans, score(mat[0][1], mat[1][2], mat[2][0]));
  ans = max(ans, score(mat[0][2], mat[1][0], mat[2][1]));
  ans = max(ans, score(mat[0][2], mat[1][1], mat[2][0]));
  cout << fixed << ans << endl;
  return 0;
}