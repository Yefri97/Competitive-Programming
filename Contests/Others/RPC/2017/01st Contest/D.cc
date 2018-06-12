/*
 *  RPC 01st Contest 2017
 *  Problem D: Complexity
 *  Status: Accepted
 */

#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cout << #x << ": " << x << endl
//#define endl '\n'

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  string s;
  while (cin >> s) {
    int ans = 10000000;
    vector<int> count(255, 0);
    int ss = s.size();
    for (int i = 0; i < s.size(); i++) count[s[i]]++;
    for (char i = 'a'; i < 'z'; i++) {
      for (char j = i + 1; j <= 'z'; j++) {
        if (count[i] && count[j]) {
          int tmp = ss - count[i] - count[j];
          ans = min(ans, tmp);
        }
      }
    }
    for (char i = 'a'; i <= 'z'; i++) {
      if (count[i]) {
        int tmp = ss - count[i];
        ans = min(ans, tmp);
      }
    }
    cout << ans << endl;
  }
}
