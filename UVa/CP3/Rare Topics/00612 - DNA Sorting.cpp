#include <bits/stdc++.h>
using namespace std;

int measure(string a) {
  int ans = 0;
  for (int i = 0; i < a.size() - 1; i++) {
    for (int c = a[i], j = i + 1; j < a.size(); j++) {
      if (c > (int)a[j]) ans++;
    }
  }
  return ans;
}

bool cmp(string a, string b) {
  return measure(a) < measure(b);
}

int main() {
  int t; cin >> t;
  while (t--) {
    int n, m; cin >> n >> m;
    vector<string> vs(m);
    for (int i = 0; i < m; i++)
      cin >> vs[i];
    stable_sort(vs.begin(), vs.end(), cmp);
    for (int i = 0; i < m; i++)
      cout << vs[i] << endl;
    if (t) cout << endl;
  }
  return 0;
}