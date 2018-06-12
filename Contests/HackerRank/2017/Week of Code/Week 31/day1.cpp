#include <bits/stdc++.h>
using namespace std;

set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'y'};

bool check(string s) {
  for (int i = 1; i < s.size(); i++) {
    if ((s[i] == s[i - 1]) or (vowels.count(s[i]) and vowels.count(s[i - 1])))
      return false;
  }
  return true;
}

int main() {
  string line; cin >> line;
  bool ans = check(line);
  cout << (ans ? "Yes" : "No") << endl;
  return 0;
}