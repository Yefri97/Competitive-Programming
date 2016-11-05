#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  while (cin >> n && n != -1) {
    int ans = 0;
    for (int a = 1; a <= n; a++) for (int b = 0; b <= a && b * a <= n; b++) {
      if ((n - a * b) % (a + b) == 0) {
        int c = (n - a * b) / (a + b);
        if (c <= b) ans++;
      } 
    }
    cout << ans << endl;
  }
  return 0;
}