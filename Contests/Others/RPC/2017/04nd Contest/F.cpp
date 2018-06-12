/*
 *  RPC 04st Contest 2017
 *  Problem F: Funny Strings
 *  Outcome: Accepted | Category: Longest Increasing Subsequence
 */
#include <bits/stdc++.h>
#define endl '\n'
#define to_int(C) (C - 'a')
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while (t--) {
    string s; cin >> s;
    int k; cin >> k;
    int n = s.size();
    vector<int> lis(n, 1);
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if ((to_int(s[j]) + k) % 26 <= to_int(s[i]))
          lis[i] = max(lis[i], lis[j] + 1);
      }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
      ans = max(ans, lis[i]);
    cout << ans << endl;
  }
  return 0;
}