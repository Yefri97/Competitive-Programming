#include <bits/stdc++.h>
using namespace std;

int highestBit(int n) {
  n |= n >> 1;
  n |= n >> 2;
  n |= n >> 4;
  n |= n >> 8;
  n |= n >> 16;
  n &= ~(n >> 1);
  return n;
}

int josephus2(int n) {
  int k = n - highestBit(n);
  int ans = 2 * k + 1;
  return ans;
}

int main() {
  int pt[10];
  for (int i = 0, p = 1; i < 7; i++, p *= 10)
    pt[i] = p;
  char x, y, e, z;
  while (cin >> x >> y >> e >> z && (x != '0' || y != '0' || z != '0')) {
    int n = ((x - '0') * 10 + (y - '0')) * pt[(z - '0')];
    int ans = josephus2(n);
    cout << ans << endl;
  }
  return 0;
}