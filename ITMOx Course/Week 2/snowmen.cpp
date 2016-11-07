#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {

  freopen("snowmen.in", "rt", stdin);
  freopen("snowmen.out", "wt", stdout);

  int n; scanf("%d", &n);
  vector<int> p(n + 1), acc(n + 1);
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    int t, m; scanf("%d %d", &t, &m);
    if (m > 0) {
      p[i] = t;
      ans += acc[i] = m + acc[t];
    } else {
      p[i] = p[p[t]];
      ans += acc[i] = acc[p[t]];
    }
  }
  cout << ans << endl;
  return 0;
}