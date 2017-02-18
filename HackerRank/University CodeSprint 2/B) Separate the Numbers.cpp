#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string s;

bool solver(int id, ll prev) {
  if (id == s.size()) return true;
  for (int i = 1; id + i <= s.size(); i++) {
    string num = s.substr(id, i);
    ll curr = atoll(num.c_str());
    if (num[0] == '0' && num.size() > 1) return false;
    if (curr == prev + 1) return solver(id + i, curr);
  }
  return false;
}

int main() {
  int q; cin >> q;
  while (q--) {
    cin >> s;
    ll ans = -1;
    for (int i = 1; 2 * i <= s.size(); i++) {
      ll x = atoll(s.substr(0, i).c_str());
      if (solver(i, x)) {
        ans = x;
        break;
      }
    }
    if (ans != -1) {
      cout << "YES " << ans << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}