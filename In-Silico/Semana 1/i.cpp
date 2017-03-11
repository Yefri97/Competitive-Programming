#include <bits/stdc++.h>
using namespace std;

int mod(int a, int b) { return ((a % b) + b) % b; }

int main() {
  int n, k, q; cin >> n >> k >> q;
  int arr[n + 10];
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  while (q--) {
    int x; cin >> x;
    cout << mod(x - k, n) << endl;
  }
  return 0;
}