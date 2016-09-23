#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  while (cin >> n >> k) {
    int ans = n, c = n, b = 0;
    while (c) {
      b += c;
      c = b / k;
      b = b % k;
      ans += c;
    }
    cout << ans << endl;
  }
  return 0;
}