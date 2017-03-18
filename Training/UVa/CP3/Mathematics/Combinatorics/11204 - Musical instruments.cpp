#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX_N = 40;

int main() {
  int t; cin >> t;
  while (t--) {
    int arr[MAX_N]; memset(arr, 0, sizeof arr);
    int n, m; cin >> n >> m;
    while (m--) {
      for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x == 1) arr[i]++;
      }
    }
    ll ans = 1;
    for (int i = 0; i < n; i++) if (arr[i]) {
      ans *= (ll)arr[i];
    }
    cout << ans << endl;
  }
  return 0;
}