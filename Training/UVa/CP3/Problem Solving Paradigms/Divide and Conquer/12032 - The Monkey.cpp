// Binary Search the Answer
#include <bits/stdc++.h>
using namespace std;

bool can(vector<int> &v, int x) {
  for (int i = 1; i < v.size(); i++) {
    if (v[i] - v[i - 1] > x) return false;
    if (v[i] - v[i - 1] == x) x--;
  }
  return true;
}

int main() {
  int tc, t = 0; cin >> tc;
  while (tc--) {
    int n; cin >> n;
    vector<int> rungs(n + 1);
    for (int i = 1; i <= n; i++)
      cin >> rungs[i];
    int maxval = 0;
    for (int i = 1; i <= n; i++)
      maxval = max(maxval, rungs[i] - rungs[i - 1]);
    int lo = maxval - 1, hi = rungs[n];
    while (hi - lo > 1) {
      int mid = (hi + lo) / 2;
      if (can(rungs, mid))
        hi = mid;
      else
        lo = mid;
    }
    cout << "Case " << ++t << ": " << hi << endl;
  }
  return 0;
}