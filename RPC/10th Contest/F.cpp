/*
 *  RPC 10-th Contest 2016
 *  Problem F: ConcatFibos
 *  Status: Accepted
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MX = 92;

int main() {
  ll fib[MX + 10]; fib[0] = fib[1] = 1;
  string sfib[MX + 10]; sfib[0] = sfib[1] = "1";
  for (int i = 2; i < MX; i++) {
    fib[i] = fib[i - 1] + fib[i - 2];
    sfib[i] = to_string(fib[i]);
  }

  set<string> concatFibos;
  for (int i = 0; i < MX; i++) {
    for (int j = 0; j < MX; j++) {
      if (i == j) continue;
      concatFibos.insert(sfib[i] + sfib[j]);
    }
  }

  string line;
  while (cin >> line) {
    vector< vector<int> > freq(10);
    for (int i = 0; i < line.size(); i++) if(isdigit(line[i])) {
      freq[line[i] - '0'].push_back(i);
    }
    int ans = 0;
    for (set<string>::iterator it = concatFibos.begin(); it != concatFibos.end(); it++) {
      string s = *it;
      int ok = 1;
      for (int j = 0, last = -1; j < s.size(); j++) {
        int id = s[j] - '0';
        vector<int>::iterator it = upper_bound(freq[id].begin(), freq[id].end(), last);
        if (it == freq[id].end()) { ok = 0; break; }
        last = *it;
      }
      ans += ok;
    }
    cout << ans << endl;
  }

  return 0;
}