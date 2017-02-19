// Iterative (One loop, Linear Scan)
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

int main() {
  int k;
  while (cin >> k) {
    vector<ii> ans;
    for (int y = k + 1; y <= 2 * k; y++) {
      if ((k * y) % (y - k) == 0)
        ans.push_back(ii((k * y) / (y - k), y));
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
      cout << "1/" << k << " = " << "1/" << ans[i].first << " + 1/" << ans[i].second << endl;
  }
  return 0;
}