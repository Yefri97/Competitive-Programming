#include <bits/stdc++.h>
using namespace std;

int main() {
  string sb;
  while (cin >> sb && sb != "0") {
    int ans = 0;
    for (int i = sb.size() - 1, pot = 2; i >= 0; i--) {
      ans += (sb[i] - '0') * (pot - 1);
      pot *= 2;
    }
    cout << ans << endl;
  }
  return 0;
}