#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MAX_N = 5010;
string ans, str = "NOP";
char vc[MAX_N + 10];

bool cmp(int len) {
  for (int i = 1; 2 * i <= len; i++) {
    int ok = 1;
    for (int j = 0; j < i && ok; j++)
      if (vc[len - 2 * i + j] != vc[len - i + j]) ok = 0;
    if (ok) return false;
  }
  return true;
}

int solver(int id) {
  if (id == MAX_N) { ans = vc; return 1; }
  for (int i = 0; i < 3; i++) {
    vc[id] = str[i];
    if (cmp(id + 1) && solver(id + 1))
      return 1;
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  solver(0);
  int n;
  while (cin >> n && n) {
    cout << ans.substr(0, n) << endl;
  }
  return 0;
}