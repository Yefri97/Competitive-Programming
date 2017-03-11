#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, m, s;
  char c, b;
  cin >> h >> b >> m >> b >> s >> c >> b;
  if ((c == 'P' and h != 12) or (c == 'A' and h == 12))
    h = (h + 12) % 24;
  cout << setfill('0');
  cout << setw(2) << h << ":" << setw(2) << m << ":" << setw(2) << s << endl;
  return 0;
}