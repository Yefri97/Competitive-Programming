#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1000, INF = 1e8;
int n, h, total, arr[MAX_N + 10], memo[MAX_N + 10][MAX_N + 10];

int solver(int id, int d, int pos) {
  if ((n - id) * h < total - pos) return INF;
  if (id == n - 1) return 0;
  if (memo[id][d] != -1) return memo[id][d];
  if (d <= 0 || d > h) return memo[id][d] = solver(id + 1, arr[id + 1] + (d - h), pos + h) + 1;
  return memo[id][d] = min(solver(id + 1, arr[id + 1], pos + d), solver(id + 1, arr[id + 1] - (h - d), pos + h) + 1);
}

int main() {
  while (cin >> n >> h && n != -1 && h != -1) {
    total = 0; n--;
    for (int i = 0; i < n; i++) {
      int x; cin >> x;
      total += x;
      arr[i] = x;
    }
    memset(memo, -1, sizeof memo);
    int ans = solver(0, arr[0], 0);
    cout << ((ans > n)? -1 : ans) << endl;
  }
  return 0;
}