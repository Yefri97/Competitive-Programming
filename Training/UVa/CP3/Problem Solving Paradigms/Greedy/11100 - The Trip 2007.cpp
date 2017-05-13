#include <bits/stdc++.h>
using namespace std;

int main() {
  bool first = true;
  int n;
  while (cin >> n and n) {
    if (!first) cout << endl; first = false;
    
    map<int, int> counting;
    for (int i = 0; i < n; i++) {
      int x; cin >> x;
      counting[x]++;
    }
    
    int k = 0;
    for (map<int, int>::iterator it = counting.begin(); it != counting.end(); it++)
      k = max(k, it->second);

    cout << k << endl;
    
    vector< vector<int> > ans(k);
    int id = 0;
    for (map<int, int>::iterator it = counting.begin(); it != counting.end(); it++) {
      while ((it->second)--) {
        ans[id].push_back(it->first);
        id = (id + 1) % k;
      }
    }
    
    for (int i = 0; i < k; i++) {
      cout << ans[i][0];
      for (int j = 1; j < ans[i].size(); j++)
        cout << " " << ans[i][j];
      cout << endl;
    }
  }
  return 0;
}