#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

int main() {
  int k;
  while (cin >> k) {
    vector<ii> vp;
    for (int y = k + 1; y <= 2 * k; y++) {
      double x = ((double) y * k / (y - k));
      if (x == (int) x)
        vp.push_back(ii(x, y));
    }
    cout << vp.size() << endl;
    for (int i = 0; i < vp.size(); i++)
      cout << "1/" << k << " = " << "1/" << vp[i].first << " + 1/" << vp[i].second << endl;
  }
  return 0;
}