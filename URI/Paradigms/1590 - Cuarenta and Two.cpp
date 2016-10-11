#include <bits/stdc++.h>
using namespace std;

int main() {
  int t; cin >> t;
  while (t--) {
    int ans = 0, mm[40];
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; i++)
      cin >> mm[i];
    for (int i = 31; i >= 0; i--) {
      int cont = 0;
      for (int j = 0; j < n; j++) 
        if (mm[j] & (1 << i)) cont++;
      if (cont < k) continue;
      for (int j = 0; j < n; j++)
        if (!(mm[j] & (1 << i))) mm[j] = 0;
      ans |= (1 << i);
    }
    cout << ans << endl;
  }
  return 0;
}