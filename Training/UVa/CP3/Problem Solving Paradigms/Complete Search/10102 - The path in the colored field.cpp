// Three or More Nested Loops, Easy
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  while (cin >> n) {
    vector< vector<char> > board(n, vector<char>(n));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        cin >> board[i][j];
    int ans = -1;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if (board[i][j] == '1') {
      int mmin = n * n + 1;
      for (int k = 0; k < n; k++) for (int l = 0; l < n; l++) if (board[k][l] == '3') {
        mmin = min(mmin, abs(k - i) + abs(l - j));
      }
      ans = max(ans, mmin);
    }
    cout << ans << endl;
  }
  return 0;
}