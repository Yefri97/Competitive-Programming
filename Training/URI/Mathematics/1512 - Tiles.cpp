#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, a, b;
  while (cin >> n >> a >> b && (n + a + b)) {
    int mcm = (a * b) / __gcd(a, b);
    cout << (n / a) + (n / b) - (n / mcm) << endl;
  }
  return 0;
}