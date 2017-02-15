/*
 *  RPC 01st Contest 2017
 *  Problem C: Class Time
 *  Status: Accepted
 */

#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cout << #x << ": " << x << endl
#define endl '\n'

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int n; string line;
  while (getline(cin, line)) {
    n = atoi(line.c_str());
    vector<string> ans;
    for (int i = 0; i < n; i++) {
      getline(cin, line);
      stringstream ss; ss << line;
      string s1, s2; ss >> s2; ss >> s1;
      ans.push_back(s1 + " " + s2);
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i< n; i++) {
      stringstream ss; ss << ans[i];
      string s1, s2; ss >> s2; ss >> s1;
      cout << s1 << " " << s2 << endl;
    }
  }
  
}
