/*
 *  ACM ICPC XXX Colombian Programming Contest 2016
 *  Problem F: Funny Cardiologist
 *  Status: Accepted \ DP (0-1 KnapSack)
 */

#include <bits/stdc++.h>
using namespace std;

struct point {
  double x, y;
  point() {}
  point(double _x, double _y) : x(_x), y(_y) {}
};

double dist(point p1, point p2) { return hypot(p1.x - p2.x, p1.y - p2.y); }

const int MAX_N = 256;
int n;
double memo[MAX_N + 10][MAX_N + 10][MAX_N + 10];
point arr[MAX_N + 10];

double solver(int curr, int prev, int k) {
  if (curr == n - 1) return memo[curr][prev][k] = dist(arr[curr], arr[prev]);
  if (memo[curr][prev][k] != -1.0) return memo[curr][prev][k];
  if (k == 0) return memo[curr][prev][k] = solver(curr + 1, curr, 0) + dist(arr[curr], arr[prev]);
  return memo[curr][prev][k] = min(solver(curr + 1, prev, k - 1), solver(curr + 1, curr, k) + dist(arr[curr], arr[prev]));
}

int main() {
  int k;
  while (cin >> n >> k) {
    for (int i = 0; i < n; i++)
      cin >> arr[i].x >> arr[i].y;

    for (int i = 0; i < n + 1; i++) for (int j = 0; j < n + 1; j++) for (int l = 0; l < k + 1; l++)
      memo[i][j][l] = -1.0;
    double ans = solver(1, 0, k);
    cout << fixed << setprecision(3) << ans << endl;
  }
}