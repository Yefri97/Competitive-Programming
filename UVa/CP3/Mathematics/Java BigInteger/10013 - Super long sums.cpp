#include <bits/stdc++.h>
using namespace std;

string add(string a, string b) {
  string target(a.size(), ' ');
  int carry = 0;
  for (int i = target.size() - 1; i >= 0; i--) {
    int sum = (a[i] - '0') + (b[i] - '0') + carry;
    target[i] = (sum) % 10 + '0';
    carry = sum / 10;
  }
  return target;
}

int main() {
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    string a, b;
    while (n--) {
      char ca, cb; cin >> ca >> cb;
      a.push_back(ca);
      b.push_back(cb);
    }
    string ans = add(a, b);
    cout << ans << endl;
    if (t) cout << endl;
  }
  return 0;
}