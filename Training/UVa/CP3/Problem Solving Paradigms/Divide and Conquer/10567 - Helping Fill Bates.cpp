// Binary Search
#include <bits/stdc++.h>
using namespace std;

int to_int(char c) { return c - (isupper(c) ? 'A' - 26 : 'a'); }

int main() {
  string candidates; cin >> candidates;
  vector< vector<int> > freq(52);
  for (int i = 0; i < candidates.size(); i++) {
    int c = to_int(candidates[i]);
    freq[c].push_back(i);
  }
  int q; cin >> q;
  while (q--) {
    string query; cin >> query;
    int a, b;
    bool ans = true;
    for (int i = 0, idx = -1; i < query.size(); i++) {
      int c = to_int(query[i]);
      vector<int> v = freq[c];
      vector<int>::iterator it = upper_bound(v.begin(), v.end(), idx);
      if (it == v.end()) {
        ans = false;
        break;
      }
      idx = *it;
      if (i == 0) a = idx;
      if (i == query.size() - 1) b = idx;
    }
    if (ans)
      cout << "Matched " << a << " " << b << endl;
    else
      cout << "Not matched" << endl;
  }
  return 0;
}