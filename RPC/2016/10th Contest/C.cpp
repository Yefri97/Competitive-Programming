/*
 *  RPC 10-th Contest 2016
 *  Problem C: Cacho
 *  Status: Accepted
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
  int n; cin >> n;
  while (n--) {
    int v[10];
    for (int i = 0; i < 5; i++)
      cin >> v[i];
    int ok = 1;
    for (int i = 0; i < 4; i++)
      if (v[i + 1] != v[i] + 1) ok = 0;
    if (ok)
      cout << "Y" << endl;
    else
      cout << "N" << endl;
  }
  return 0;
}
