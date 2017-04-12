// Binary Search the Answer
#include <bits/stdc++.h>
using namespace std;

bool can(vector<int> &v, int m, int x) {
  int acc = 0;
  for (int i = 0, j = 1; i < v.size(); i++) {
    if (acc + v[i] > x) {
      j++;
      if (j > m) return false;
      acc = 0;
    }
    acc += v[i];
  }
  return true;
}

int main() {
  int n;
  while (cin >> n) {
    int m; cin >> m;
    vector<int> vessels(n);
    int maxval = 0, acc = 0;
    for(int i = 0; i < n; i++) {
      int x; cin >> x;
      maxval = max(maxval, x);
      acc += x;
      vessels[i] = x;
    }
    int lo = maxval - 1, hi = acc;
    while (hi - lo > 1) {
      int mid = (hi + lo) / 2;
      if (can(vessels, m, mid))
        hi = mid;
      else
        lo = mid;
    }
    cout << hi << endl;
  }
  return 0;
}