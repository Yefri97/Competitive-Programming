#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 15;
int n, arr[MAX_N + 10];

int solver(int id, int val) {
  if (id == n) return 0;
  if (arr[id] > val) return solver(id + 1, val);
  return max(solver(id + 1, val), solver(id + 1, val - arr[id]) + 1);
}

int main() {
  ifstream cin("win.in");
  ofstream cout("win.out");

  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  int ans = solver(0, 18000);
  cout << ans << endl;
  return 0;
}