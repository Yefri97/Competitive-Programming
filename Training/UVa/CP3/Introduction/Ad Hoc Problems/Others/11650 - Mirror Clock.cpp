#include <bits/stdc++.h>
using namespace std;

int hours(int n) {
  return (24 - n - 1) % 12 + 1;
}

int minutes(int n) {
  return (120 - n) % 60;
}

int main() {
  cout << setfill('0');
  int t; cin >> t;
  while (t--) {
    int a, b; char c;
    cin >> a >> c >> b;
    int h, m;
    h = hours(a + (b > 0));
    m = minutes(b);
    cout << setw(2) << h << ":" <<  setw(2) << m << endl;
  }
  return 0;
}