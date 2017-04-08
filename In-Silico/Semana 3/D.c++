/*
 *  ITMOx Course - 2nd Week Problems
 *  Problem: Bracket Sequence
 *  Level: Easy
 */
#include <bits/stdc++.h>
#define endl '\n'
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
  ios::sync_with_stdio(false);  // Fast input - output
  ifstream fin("input.txt");    // File Input
  ofstream fout("output.txt");  // File Output
  /*** Code ***/
  int n; fin >> n;
  while (n--) {
    string s; fin >> s;
    bool ans = check(s);
    fout << ((ans)? "YES" : "NO") << endl;
  }
  return 0;
}