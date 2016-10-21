#include <bits/stdc++.h>
using namespace std;

int main() {
  ifstream cin("prepare.in");
  ofstream cout("prepare.out");
  int arr[5][110];
  int n; cin >> n;
  for (int i = 0; i < n; i++)
    cin >> arr[0][i];
  for (int i = 0; i < n; i++)
    cin >> arr[1][i];
  int ans = 0, p = 0, t = 0;
  for (int i = 0; i < n; i++) {
    if (arr[0][i] > arr[1][i]) {
      ans += arr[0][i];
      p++;
    } else {
      ans += arr[1][i];
      t++;
    }
  }
  if (p == 0 || t == 0) {
    int mmin = 1000;
    for (int i = 0; i < n; i++)
      mmin = min(mmin, abs(arr[0][i] - arr[1][i]));
    ans -= mmin;
  }
  cout << ans << endl;
  return 0;
}