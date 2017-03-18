// Backtracking easy
#include <bits/stdc++.h>
using namespace std;

const int kSize = 8, kInf = 100;
int arr[kSize + 10], row[kSize + 10];

bool place(int r, int c) {
  for (int i = 0; i < c; i++) {
    if (row[i] == r || abs(row[i] - r) == abs(i - c))
      return false;
  }
  return true;
}

int solver(int id) {
  if (id == kSize) {
    int value = 0;
    for (int i = 0; i < kSize; i++)
      value += ((arr[i] - 1) != row[i]);
    return value;
  }
  int value = kInf;
  for (int i = 0; i < kSize; i++) {
    if (place(i, id)) {
      row[id] = i;
      value = min(value, solver(id + 1));
    }
  }
  return value;
}

int main() {
  int tc = 0;
  while (cin >> arr[0]) {
    for (int i = 1; i < kSize; i++)
      cin >> arr[i];
    int ans = solver(0);
    cout << "Case " << ++tc << ": " << ans << endl;
  }
  return 0;
}