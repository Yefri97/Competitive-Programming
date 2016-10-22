#include <bits/stdc++.h>
using namespace std;

int lcm (int a, int b) {
  return (a / __gcd(a, b)) * b;
}

int main() {
  //ifstream cin("testgen.in");
  //ofstream cout("testgen.out");
  int k; cin >> k;
  int num = 1;
  for (int i = 2; true; i++) {
    int t = lcm(num, i);
    if (t > k) break;
    num = t;
  }
  int ans = k - num + 1;
  cout << ans << endl;
  return 0;
}