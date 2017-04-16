#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  vector<int> odd, even;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    if (x & 1) odd.push_back(x);
    else even.push_back(x);
  }
  sort(odd.rbegin(), odd.rend());
  int ans = odd[0];
  for (int i = 1; i < odd.size(); i += 2)
    if (i + 1 < odd.size() and odd[i] + odd[i + 1] > 0)
      ans += odd[i] + odd[i + 1];
  for (int i = 0; i < even.size(); i++)
    if (even[i] > 0)
      ans += even[i];
  cout << ans << endl;
  return 0;
}