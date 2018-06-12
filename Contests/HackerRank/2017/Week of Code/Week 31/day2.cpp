#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &v) {
  for (int i = 1; i < v.size(); i++) {
    if (v[i] - v[i - 1] == 1) continue;
    if (v[i - 1] - v[i] == 1) swap(v[i], v[i - 1]);
  }
  for (int i = 1; i < v.size(); i++) {
    if (v[i - 1] > v[i])
      return false;
  }
  return true;
}

int main() {
  int q; cin >> q;
  while (q--) {
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
      cin >> v[i];
    bool ans = check(v);
    cout << (ans ? "Yes" : "No") << endl;
  }
  return 0;
}