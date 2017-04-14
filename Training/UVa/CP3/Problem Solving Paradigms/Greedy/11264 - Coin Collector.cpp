// Greedy Easier
#include <bits/stdc++.h>
using namespace std;

int main() {
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
      cin >> coins[i];
    int ans = 0, acc = 0;
    for (int i = 0; i < n - 1; i++) {
      if (acc + coins[i] < coins[i + 1])
        acc += coins[i], ans++;
    }
    cout << ans + 1 << endl;
  }
  return 0;
}