/*
 *  RPC 10-th Contest 2016
 *  Problem H: Homework
 *  Status: Accepted
 */

#include <bits/stdc++.h>

using namespace std;

bool is_int(double x) {
  return int(x) == x;
}

int main() {
  int t; cin >> t;
  while (t--) {
    double s; cin >> s;
    double n = (sqrt(8 * s + 1) - 3) / 2;
    if (is_int(n))
      cout << n << endl;
    else
      cout << "No solution" << endl;
  }
  return 0;
}
