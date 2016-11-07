#include <bits/stdc++.h>
using namespace std;

bool check(string s) {
  stack<char> sc;
  for (int i = 0; i < s.size(); i++) {
    char c = s[i];
    if (c == '(' || c == '[') {
      sc.push(c);
    } else {
      if (sc.empty()) return false;
      if ((c == ')' && sc.top() == '(') || (c == ']' && sc.top() == '['))
        sc.pop();
      else
        return false;
    }
  }
  return sc.empty();
}

int main() {
  ifstream cin("brackets.in");
  ofstream cout("brackets.out");
  string s;
  while (cin >> s) {
    bool ans = check(s);
    cout << ((ans)? "YES" : "NO") << endl;
  }
  return 0;
}