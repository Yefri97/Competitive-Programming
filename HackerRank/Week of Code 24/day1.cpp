#include <bits/stdc++.h>
using namespace std;

int main() {
  int s, t; cin >> s >> t;
  int a, b; cin >> a >> b;
  int m, n; cin >> m >> n;
  int apples = 0, orange = 0;
  while (m--) {
    int d; cin >> d;
    if (a + d >= s && a + d <= t) apples++;
  }
  while (n--) {
    int d; cin >> d;
    if (b + d <= t && b + d >= s) orange++;
  }
  cout << apples << endl;
  cout << orange << endl;
  return 0;
}