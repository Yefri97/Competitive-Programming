#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1000;
int arr[MAX_N + 10], memo[MAX_N + 10][MAX_N + 10];

int d(int a, int b) {
  return min(abs(a - b), 24 - abs(a - b));
}

int solver(int i, int j) {
  if (i > j) return 0;
  if (memo[i][j] != -1) return memo[i][j];
  return memo[i][j] = min(solver(i + 2, j) + d(arr[i], arr[i + 1]), solver(i + 1, j - 1) + d(arr[i], arr[j]));
}

int main() {
  int n; cin >> n;
  for (int i = 0; i < n; i++) 
    cin >> arr[i];
  sort(arr, arr + n);
  memset(memo, -1, sizeof memo);
  int ans = solver(0, n - 1);
  cout << ans << endl;
  return 0;
}