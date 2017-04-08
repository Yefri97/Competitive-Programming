/*
 *  ITMOx Course - 2nd Week Problems
 *  Problem: Postfix Notation
 *  Level: Easy
 */
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
  ios::sync_with_stdio(false);  // Fast input - output
  ifstream fin("input.txt");    // File Input
  ofstream fout("output.txt");  // File Output
  /*** Code ***/
  stack<int> s;
  int n; fin >> n;
  while (n--) {
    char c; fin >> c;
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
  fout << s.top() << endl;
  return 0;
}