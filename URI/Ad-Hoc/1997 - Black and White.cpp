#include <bits/stdc++.h>
using namespace std;

int main() {
  string a, b;
  while (cin >> a >> b && a != "*" && b != "*") {
    int ans = 0;
    for (int i = 0; i < a.size(); i++) {
      int done = 0;
      while ((a[i] == 'B' && b[i] == 'N') || (a[i] == 'N' && b[i] == 'B')) { done = 1; i++; }
      if (done) ans++;
    }
    cout << ans << endl;
  }
  return 0;
}