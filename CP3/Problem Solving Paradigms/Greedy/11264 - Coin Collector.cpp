#include <bits/stdc++.h>
using namespace std;

int main() {
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    long long v[1000 + 10];
    for (int i = 0; i < n; i++)
      cin >> v[i];
    int ans = 2;
    long long s = 1;
    for (int i = 1; i < n - 1; i++) if (s + v[i] < v[i + 1]) {
      s += v[i];
      ans++;
    }
    cout << ans << endl;
  }
  return 0;
}