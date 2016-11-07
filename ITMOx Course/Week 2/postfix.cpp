#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
  ifstream cin("postfix.in");
  ofstream cout("postfix.out");
  stack<int> s;
  char c;
  while (cin >> c) {
    if (c == '+' || c == '-' || c == '*') {
      int b = s.top(); s.pop();
      int a = s.top(); s.pop();
      if (c == '+') s.push(a + b);
      if (c == '-') s.push(a - b);
      if (c == '*') s.push(a * b);
    } else {
      s.push(c - '0');
    }
  }
  cout << s.top() << endl;
  return 0;
}