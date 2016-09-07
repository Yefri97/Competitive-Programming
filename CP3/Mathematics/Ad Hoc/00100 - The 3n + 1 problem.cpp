#include <bits/stdc++.h>

using namespace std;

int sol(int n) {
  int cont = 1;
  while (n != 1) {
    if (n % 2)
      n = 3 * n + 1;
    else
      n = n / 2;
    cont++;
  }
  return cont;
}

int main() {
  int ta, tb;
  while (cin >> ta >> tb) {
    int a = min(ta, tb), b = max(ta, tb);
    int ans = -1;
    for (int i = a; i <= b; i++) {
      ans = max(ans, sol(i));
    }
    cout << ta << " " << tb << " " << ans << endl;
  }
  return 0;
}