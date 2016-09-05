#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  while (cin >> n) {
    cout << "TERM " << n << " IS ";
    int pos = ceil((sqrt(8.0 * (double) n + 1) - 1) / 2);
    int a = 1, b = pos, x = (b * (b + 1)) / 2 - n;
    a += x; b -= x;
    if (pos & 1) 
      cout << a << "/" << b << endl;
    else
      cout << b << "/" << a << endl;
  }
  return 0;
}