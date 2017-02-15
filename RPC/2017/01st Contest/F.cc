/*
 *  RPC 01st Contest 2017
 *  Problem F: Egg Drop
 *  Status: Accepted
 */

#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cout << #x << ": " << x << endl
#define endl '\n'

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int n, k;
  while (cin >> n >> k) {
    int low = 1, high = k, t;
    string s;
    vector<int> used(k + 1, 0);
    for (int i = 0; i < n; i++) {
      cin >> t >> s;
      if (s == "SAFE") {
        low = max(low, t);
      }else{
        high = min(high, t);
      }
    }
    int dif = high - low - 1;
    if (dif)  
      cout << low + 1 << " " << high - 1 << endl;
    else
      cout << high << " " << low << endl;
  }
}
