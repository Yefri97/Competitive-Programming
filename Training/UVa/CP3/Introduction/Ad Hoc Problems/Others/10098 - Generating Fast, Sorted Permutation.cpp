#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n; cin >> n;
  while (n--) {
    string s; cin >> s;
    sort(s.begin(), s.end());
    do {
      cout << s << endl;
    } while (next_permutation(s.begin(), s.end()));
    cout << endl;
  }
  return 0;
}