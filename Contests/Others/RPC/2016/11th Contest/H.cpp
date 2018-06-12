/*
 *  RPC 11-th Contest 2016
 *  Problem H: huaauhahhuahau
 *  Status: Accepted
 */

#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s) {
  for (int i = 0; i < s.size(); i++)
    if (s[i] != s[s.size() - i - 1]) return false;
  return true;
}

int main() {
  string line;
  while (cin >> line) {
    string s;
    for (int i = 0; i < line.size(); i++) {
      char c = line[i];
      if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        s.push_back(c);
    }
    cout << ((isPalindrome(s))? "S" : "N") << endl;
  }
  return 0;
}