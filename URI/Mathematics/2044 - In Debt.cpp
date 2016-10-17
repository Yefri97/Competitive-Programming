#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  while (cin >> n && n != -1) {
    int acc = 0, cont = 0;
    while (n--) {
      int x; cin >> x;
      acc = (acc + x) % 100;
      if (acc == 0) cont++;
    }
    cout << cont << endl;
  }
  return 0;
}