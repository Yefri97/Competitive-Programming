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

double dist(point a, point b) { return hypot(b.x - a.x, b.y - b.y); }

const int MAX_N = 300;
int n;
point arr[MAX_N + 10];

double solver(int id, int k) {
  if (id == n - 1) return dist(arr[id], arr[id - 1]);
  if (k == 0) return solver(id + 1, 0) + dist(arr[id], arr[id - 1]);
  return min( solver(id + 1, k - 1) + dist(arr[id - 1], arr[id + 1]) - dist(arr[id - 1], arr[id]) - dist(arr[id], arr[id + 1]),
              solver(id + 1, k) + dist(arr[id], arr[id - 1]));
}

int main() {
  int k;
  while (cin >> n >> k) {
    for (int i = 0; i < n; i++)
      cin >> arr[i].x >> arr[i].y;
    double ans = solver(1, k);
    cout << fixed << setprecision(3) << ans << endl;
  }
}