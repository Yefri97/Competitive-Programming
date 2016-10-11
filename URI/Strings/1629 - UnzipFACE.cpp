#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  while (cin >> n) {
    while (n--) {
      int a = 0, b = 0;
      string s; cin >> s;
      for (int i = 0; i < s.size(); i++) {
        if (i % 2) b += s[i] - '0';
        else a += s[i] - '0';
      }
      string sa = to_string(a), sb = to_string(b);
      int ans = 0;
      for (int i = 0; i < sa.size(); i++)
        ans += sa[i] - '0';
      for (int i = 0; i < sb.size(); i++)
        ans += sb[i] - '0';
      cout << ans << endl;
    }
  }
  return 0;
}