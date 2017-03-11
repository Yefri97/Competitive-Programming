#include <bits/stdc++.h>
using namespace std;

int main() {
  int a[10], b[10];
  for (int i = 0; i < 3; i++)
    cin >> a[i];
  for (int i = 0; i < 3; i++)
    cin >> b[i];
  int ans[10]; ans[0] = ans[1] = 0;
  for (int i = 0; i < 3; i++) {
    if (a[i] == b[i]) continue;
    if (a[i] > b[i]) ans[0]++;
    else ans[1]++;
  }
  cout << ans[0] << " " << ans[1] << endl;
  return 0;
}