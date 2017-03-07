// Iterative, Fancy Technique
#include <bits/stdc++.h>
using namespace std;

const int kMaxN = 8, INF = 1e8;
int board[kMaxN + 10][kMaxN + 10];

int main() {
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        cin >> board[i][j];
    vector<int> v;
    for (int i = 0; i < n; i++) v.push_back(i);
    int ans = INF;
    do {
      int acc = 0;
      for (int i = 0; i < n; i++)
        acc += board[i][v[i]];
      ans = min(ans, acc);
    } while (next_permutation(v.begin(), v.end()));
    cout << ans << endl;
  }
  return 0;
}