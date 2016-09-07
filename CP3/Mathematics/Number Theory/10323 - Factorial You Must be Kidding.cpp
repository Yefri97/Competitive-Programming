#include <bits/stdc++.h>
using namespace std;

long long fact(long long n) {
  if (n == 1) return 1;
  return n * fact(n - 1);
}

int main() {
  int n;
  while (cin >> n) {
    if (n < 0)
      if (n % 2)
        cout << "Overflow!" << endl;
      else
        cout << "Underflow!" << endl;
    else if (n < 8)
      cout << "Underflow!" << endl;
    else if (n < 14)
      cout << fact(n) << endl;
    else
      cout << "Overflow!" << endl;
  }
  return 0;
}