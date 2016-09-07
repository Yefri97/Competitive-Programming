#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ll x;
  while (cin >> x) {
    cin.ignore();
    string line; getline(cin, line);
    istringstream iss(line);
    vector<ll> v;
    while (iss >> line)
      v.push_back(atol(line.c_str()));
    ll ans = 0;
    for (ll i = v.size() - 2, dg = 1, r = 1; i >= 0; i--, dg++, r *= x)
      ans += dg * v[i] * r;
    cout << ans << endl;
  }
  return 0;
}