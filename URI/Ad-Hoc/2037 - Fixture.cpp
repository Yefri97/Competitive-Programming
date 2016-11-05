#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  while (cin >> n && n != -1) {
    n--;
    vector<string> vs(n);
    for (int i = 0; i < n; i++) {
      cin >> vs[i];
      reverse(vs[i].begin(), vs[i].end());
    }
    string ans;
    int done = n;
    while(done) {
      for (int i = -1; i < n; i++) for (int j = i + 1; j < n; j++) {
        if (vs[j].empty()) continue;
        char a = j + 2 + '0', b = i + 2 + '0';
        if (i == -1) {
          while (vs[j].back() == '1') {
            ans.push_back(a);
            vs[j].pop_back();
          }
        } else {
          if (vs[i].empty()) continue;
          while (vs[i].back() == a && vs[j].back() == b) {
            vs[i].pop_back();
            vs[j].pop_back();
          }
        }
        if (i >= 0 && vs[i].size() == 0) done--;
        if (vs[j].size() == 0) done--;
      }
    }
    cout << ans << endl;
  }
  return 0;
}