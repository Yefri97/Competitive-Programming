// Iterative (One loop, Linear Scan)
#include <bits/stdc++.h>
using namespace std;

struct car {
  string name;
  int l, h;
};

int main() {
  int tc; cin >> tc;
  while (tc--) {
    int n; cin >> n;
    vector<car> cars(n);
    for (int i = 0; i < n; i++) {
      car c; cin >> c.name >> c.l >> c.h;
      cars[i] = c;
    }
    int q; cin >> q;
    while (q--) {
      int x; cin >> x;
      int cont = 0;
      string ans;
      for (int i = 0; i < n; i++) {
        if (cars[i].l <= x && x <= cars[i].h) {
          cont++;
          ans = cars[i].name;
        }
      }
      if (cont == 1) cout << ans << endl;
      else cout << "UNDETERMINED" << endl;
    }
    if (tc) cout << endl;
  }
  return 0;
}