// Iterative, Fancy Techniques
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

int count(int n) {
  int cont = 0;
  while (n) {
    if (n & 1) cont++;
    n >>= 1;
  }
  return cont;
}

int main() {
  int cs = 0;
  int n, k;
  while (cin >> n >> k and (n or k)) {
    vector<int> towers(n);
    for (int i = 0; i < n; i++)
      cin >> towers[i];
    
    vector<ii> overlapping;
    int m; cin >> m;
    while (m--) {
      int t; cin >> t;
      int bitmask = 0;
      for (int i = 0; i < t; i++) {
        int x; cin >> x; x--;
        bitmask |= (1 << x);
      }
      int value; cin >> value;
      overlapping.push_back(ii(bitmask, value));
    }

    int ans = -1;
    vector<int> v;
    for (int i = 0; i < (1 << n); i++) {
      vector<int> pt;
      for (int j = 0; j < n; j++)
        if (i & (1 << j))
          pt.push_back(j);
      if (pt.size() != k) continue;

      int value = 0;
      for (int j = 0; j < pt.size(); j++)
        value += towers[pt[j]];
      for (int j = 0; j < overlapping.size(); j++) {
        int bm = overlapping[j].first, op = overlapping[j].second;
        int cont = count(bm & i);
        if (cont > 1) value -= (cont - 1) * op;
      }
      
      if (value > ans) {
        ans = value;
        v = pt;
      }
    }
    cout << "Case Number  " << ++cs << endl;
    cout << "Number of Customers: " << ans << endl;
    cout << "Locations recommended:";
    for (int i = 0; i < v.size(); i++)
      cout << " " << v[i] + 1;
    cout << endl << endl;
  }
  return 0;
}