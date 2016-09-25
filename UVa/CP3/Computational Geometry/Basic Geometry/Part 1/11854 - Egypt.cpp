#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c;
  while (cin >> a >> b >> c && a + b + c) {
    int ans;
    if (a > b && a > c)
      ans = (a * a == b * b + c * c);
    else if (b > a && b > c)
      ans = (b * b == a * a + c * c);
    else
      ans = (c * c == a * a + b * b);
    if (ans)
      cout << "right" << endl;
    else
      cout << "wrong" << endl;
  }
  return 0;
}