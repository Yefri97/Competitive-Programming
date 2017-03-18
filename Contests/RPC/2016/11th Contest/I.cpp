/*
 *  RPC 11-th Contest 2016
 *  Problem I: Isosceles
 *  Status: Accepted
 */

#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 50000;
int arr[MAX_N + 10];

int main() {
  int n;
  while (cin >> n) {
    for (int i = 0; i < n; i++)
      cin >> arr[i];
    for (int i = 0, cont = 1; i < n; i++) {
      cont = min(cont, arr[i]);
      arr[i] = cont++;
    }
    for (int i = n - 1, cont = 1; i >= 0; i--) {
      cont = min(cont, arr[i]);
      arr[i] = cont++;
    }
    int ans = -1;
    for (int i = 0; i < n; i++)
      ans = max(ans, arr[i]);
    cout << ans << endl;
  }
  return 0;
}