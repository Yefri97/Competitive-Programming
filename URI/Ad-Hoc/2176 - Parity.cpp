#include <bits/stdc++.h>
using namespace std;

int main() {
  string s; cin >> s;
  int cont = 0;
  for (int i = 0; i < s.size(); i++) {
    cont += s[i] - '0';
  }
  cout << s << cont % 2 << endl;
  return 0;
}