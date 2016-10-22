#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  while (cin >> t) {
    string ans;
    for (int i = 0; i < t; i++) {
      int c, e;
      char x, sum;
      if (i) {
        cin >> sum;
        ans += " + ";
      }
      cin >> c >> x >> e;
      ans += to_string(c * e) + x;
      if (e > 2)
        ans += to_string(e - 1);
    }
    cout << ans << endl;
  }
  return 0;
}