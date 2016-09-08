#include <bits/stdc++.h>
using namespace std;

const int MX = 1000;

int main() {
  string a, b;
  while (getline(cin, a)) {
    getline(cin, b);
    int lcs[MX + 10][MX + 10]; memset(lcs, 0, sizeof lcs);
    for (int i = 1; i <= a.size(); i++) {
      for (int j = 1; j <= b.size(); j++) {
        if (a[i - 1] == b[j - 1])
          lcs[i][j] = lcs[i - 1][j - 1] + 1;
        else
          lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
      }
    }
    int ans = lcs[a.size()][b.size()];
    cout << ans << endl;
  }
  return 0;
}