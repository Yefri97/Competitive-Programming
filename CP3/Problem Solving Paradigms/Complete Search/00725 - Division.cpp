#include <bits/stdc++.h>
using namespace std;

int used;

int check(int temp) {
  while (temp) {
    used |= 1 << (temp % 10);
    temp /= 10;
  }
}

int main() {
  cout << setfill('0');
  int first = 1;
  int n;
  while (cin >> n && n) {
    if (!first) cout << endl; first = 0;
    int flag = 1;
    for (int fghij = 1234; n * fghij <= 98765; fghij++) {
      int abcde = n * fghij;
      used = (fghij < 10000);
      check(abcde);
      check(fghij);
      if (used == (1 << 10) - 1) {
        cout << setw(5) << abcde << " / " << setw(5) << fghij << " = " << n << endl;
        flag = 0;
      }
    }
    if (flag) cout << "There are no solutions for " << n << "." << endl;
  }
  return 0;
}