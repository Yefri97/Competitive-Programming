#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  while (n--) {
    string s; cin >> s;
    if (s.size() == 3) {
      if (s[0] == 'U' && s[1] == 'R') s[2] = 'I';
      if (s[0] == 'O' && s[1] == 'B') s[2] = 'I';
    }
    cout << s;
    if (n) cout << " ";
  }
  cout << endl;
  return 0;
}