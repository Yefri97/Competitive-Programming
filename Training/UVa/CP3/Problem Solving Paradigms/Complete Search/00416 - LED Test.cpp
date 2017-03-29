// Recursive Backtracking (Harder)
#include <bits/stdc++.h>
using namespace std;

int n, input[15];

int toBitsmask(string s) {
  int target = 0;
  for (int i = 0; i < s.size(); i++)
    target |= ((s[i] == 'Y') << i);
  return target;
}

int display[] = {
    toBitsmask("YYYYYYN"),  // 0
    toBitsmask("NYYNNNN"),  // 1
    toBitsmask("YYNYYNY"),  // 2
    toBitsmask("YYYYNNY"),  // 3
    toBitsmask("NYYNNYY"),  // 4
    toBitsmask("YNYYNYY"),  // 5
    toBitsmask("YNYYYYY"),  // 6
    toBitsmask("YYYNNNN"),  // 7
    toBitsmask("YYYYYYY"),  // 8
    toBitsmask("YYYYNYY")   // 9
  };

bool check(int digit, int id, int burned) {
  if (id == n) return true;
  if ((burned & input[id]) != 0) return false;
  if ((display[digit] | input[id]) != display[digit]) return false;
  return check(digit - 1, id + 1, (display[digit] ^ input[id]) | burned);
}

bool solver() {
  for (int init = 9; init >= n - 1; init--)
    if (check(init, 0, 0)) return true;
  return false;
}

int main() {
  while (cin >> n and n) {
    for (int i = 0; i < n; i++) {
      string s; cin >> s;
      input[i] = toBitsmask(s);
    }
    cout << ((solver())? "MATCH" : "MISMATCH") << endl;
  }
  return 0;
}