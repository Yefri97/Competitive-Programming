#include <bits/stdc++.h>

using namespace std;

const int MN = 1000000 + 100;

int main() {
  int n; cin >> n;
  vector<int> a(MN), b(MN);
  for (int i = 0; i < n; ++i) {
    int tmp; cin >> tmp;
    a[tmp]++;
  }
  for (int i = 0; i < n; ++i) {
    int tmp; cin >> tmp;
    b[tmp]++;
  }

  for (int i = MN - 1; i >= 1; --i) {
    int j = i;
    int any_a = -1, any_b = -1;
    while (j < MN) {
      if (a[j] > 0) any_a = j;
      if (b[j] > 0) any_b = j;
      j += i;
    }
    if (any_a != -1 && any_b != -1) {
      cout << any_a + any_b << endl;
      break;
    }
  }
  return 0;
}