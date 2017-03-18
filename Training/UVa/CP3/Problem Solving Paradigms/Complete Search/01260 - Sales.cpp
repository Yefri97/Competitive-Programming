// Iterative, Two Nested loops
#include <bits/stdc++.h>
using namespace std;

int main() {
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> sales(n);
    for (int i = 0; i < n; i++)
      cin >> sales[i];
    int ans = 0;
    for (int i = 1; i < n; i++)
      for (int j = 0; j < i; j++)
        ans += (sales[j] <= sales[i]);
    cout << ans << endl;
  } 
  return 0;
}