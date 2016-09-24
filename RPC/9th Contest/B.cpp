/*
 *  RPC 9-th Contest 2016
 *  Problem B: Tautobots and Contradicticons
 *  Status: Accepted
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  int t, cs = 0; cin >> t;
  while (t--) {
    int mm[110][5];
    cout << "Case #" << ++cs << ": ";
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
      int a, b; char c;
      cin >> a >> b >> c;
      mm[i][0] = a - 1; mm[i][1] = b - 1; mm[i][2] = (c == 'T');
    }
    int ans = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
      int cont = 0;
      for (int i = 0; i < m; i++) {
        int a = ((mask & (1 << mm[i][0])) != 0);
        int b = ((mask & (1 << mm[i][1])) != 0);
        cont += ((a)? (b == mm[i][2]) : (b != mm[i][2]));
      }
      ans += (cont == m);
    }
    cout << ans << endl;
  }
  return 0;
}