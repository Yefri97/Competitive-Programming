// Greedy Easier
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, d, r;
  while (cin >> n >> d >> r and n) {
    vector<int> morning(n), evening(n);
    for (int i = 0; i < n; i++)
      cin >> morning[i];
    for (int i = 0; i < n; i++)
      cin >> evening[i];
    sort(morning.begin(), morning.end());
    sort(evening.rbegin(), evening.rend());
    int ans = 0;
    for (int i = 0; i < n; i++)
      if (morning[i] + evening[i] > d)
        ans += (morning[i] + evening[i] - d) * r;
    cout << ans << endl;
  }
  return 0;
}