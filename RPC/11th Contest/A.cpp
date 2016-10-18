/*
 *  RPC 11-th Contest 2016
 *  Problem A: Time travel
 *  Status: Accepted
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c;
  while (cin >> a >> b >> c) {
    if (a == b || a == c || b == c || a + b == c || a + c == b || b + c == a)
      cout << "S" << endl;
    else
      cout << "N" << endl;
  }
  return 0;
}