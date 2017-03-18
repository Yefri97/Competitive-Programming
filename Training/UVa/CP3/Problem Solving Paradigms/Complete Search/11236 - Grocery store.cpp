#include <bits/stdc++.h>
using namespace std;

const int kLimit = 20e8, k = 1e6;

int main() {
  cout << fixed << setprecision(2);
  for (int a = 1; a * a * a * a <= kLimit; a++) {
    for (int b = a; a * b * b * b <= kLimit; b++) {
      for (int c = b; a * b * c * c <= kLimit; c++) {
        if (a * b * c == k) continue;
        if ((k * (a + b + c)) % (a * b * c - k) == 0) {
          int d = (k * (a + b + c)) / (a * b * c - k);
          if (d < c || (a + b + c + d) > 2000) continue;
          cout << a / 100.0 << " " << b / 100.0 << " " << c / 100.0 << " " << d / 100.0 << endl;
        }
      }
    }
  }
  return 0;
}