#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 10;
int arr[MAX_N + 10];

int main() {
  int n, total = 0; cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    total += arr[i];
  }
  int ans = 2;
  for (int i = 0; i < n && ans == 2; i++) {
    int cont = 0;
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      int a = arr[i], b = arr[j];
      if (a > b && ((a * 100 >= total * 45) || (a * 100 >= total * 40 && 100 * a >= 100 * b + total * 10)))
        cont++;
    }
    if (cont == n - 1) ans = 1;
  }
  cout << ans << endl;
  return 0;
}