// Iterative, Fancy Technique
#include <bits/stdc++.h>
using namespace std;

int main() {
  int t; cin >> t;
  while (t--) {
    int k, n; cin >> k >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
      cin >> v[i];
    bool done = false;
    for (int i = 0; i < (1 << n) & !done; i++) {
      int acc = 0;
      for (int j = 0; j < n; j++)
        if (i & (1 << j))
          acc += v[j];
      if (acc == k) done = true;
    }
    cout << ((done)? "YES" : "NO") << endl;
  }
  return 0;
}