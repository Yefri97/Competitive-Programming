#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

map<ll, int> mp;

int best(ll n) {
  map<ll, int>::iterator it = mp.upper_bound(n); it--;
  return it->second;
}

int main() {
  int g; cin >> g;
  while (g--) {
    int n, m; cin >> n >> m;
    ll x; cin >> x;
    vector<ll> A(n), B(m);
    for (int i = 0; i < n; i++)
      cin >> A[i];
    for (int i = 0; i < m; i++)
      cin >> B[i];

    mp.clear();
    ll acc = 0;
    mp[0ll] = 0;
    for (int i = 0; i < m; i++) {
      acc += B[i];
      mp[acc] = i + 1;
    }

    int ans = best(x);
    for (int i = 0; i < n; i++) {
      x -= A[i];
      if (x < 0) break;
      ans = max(ans, i + 1 + best(x));
    }

    cout << ans << endl;
  }
  return 0;
}