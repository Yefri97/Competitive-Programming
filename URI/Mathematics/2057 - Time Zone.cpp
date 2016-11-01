#include <bits/stdc++.h>
using namespace std;

int main() {
  int s, t, f; cin >> s >> t >> f;
  cout << ((s + t + f) % 24 + 24) % 24 << endl;
  return 0;
}
