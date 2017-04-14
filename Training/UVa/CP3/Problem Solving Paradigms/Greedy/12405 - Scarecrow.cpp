// Greedy Easier
#include <bits/stdc++.h>
using namespace std;

int main() {
  int tc = 0, t; cin >> t;
  while (t--) {
    int n; cin >> n;
    string line; cin >> line;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (line[i] == '.')
        ans++, i += 2;
    }
    cout << "Case " << ++tc << ": " << ans << endl;
  }
  return 0;
}