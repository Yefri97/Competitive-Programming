#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX_N = 1e5;

int main() {
  ll arr[MAX_N + 10]; arr[0] = 0;
  ll n, m;
  while (cin >> n >> m && n != -1 & m != -1) {
    for (int i = 1; i <= n; i++) {
      ll x; cin >> x;
      arr[i] = x * m + arr[i - 1];
    }
    ll ans = accumulate(arr, arr + n + 1, arr[0]);
    cout << ans << endl;
  }
  return 0;
}