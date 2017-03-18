// Backtracking easy
#include <bits/stdc++.h>
using namespace std;

const int k = 12;
int s, d, A[k], ans;

bool solver(int id) {
  if (id == k) {
    int w = 0;
    for (int i = 0; i < 5; i++) w += A[i];
    if (w > 0) return false;
    for (int i = 5; i < k; i++) {
      w += A[i];
      w -= A[i - 5];
      if (w > 0) return false;
    }
    ans = accumulate(A, A + 12, 0);
    return true;
  }
  A[id] = s;
  if (solver(id + 1)) return true;
  A[id] = -d;
  if (solver(id + 1)) return true;
  return false;
}

int main() {
  while (cin >> s >> d) {
    if (solver(0) and ans > 0)
      cout << ans << endl;
    else
      cout << "Deficit" << endl;
  }
  return 0;
}