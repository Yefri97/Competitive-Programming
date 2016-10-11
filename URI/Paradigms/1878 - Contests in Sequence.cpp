#include <bits/stdc++.h>
using namespace std;

int n, m, v[10], coef[10];

int sol(int id) {
  if (id == 2 * n) {
    for (int i = 0; i < n; i++)
      if (v[i] == v[i + n]) return 1;
    int cont = 0;
    for (int i = 0; i < n; i++)
      cont += coef[i] * (v[i] - v[i + n]);
    return (cont != 0);
  }
  int ans = 1;
  for (int i = 1; i <= m; i++) {
    v[id] = i;
    ans &= sol(id + 1);
  }
  return ans;
}

int main() {
  while (cin >> n >> m) {
    for (int i = 0; i < n; i++)
      cin >> coef[i];
    int ans = sol(0);
    cout << ((ans)? "Lucky Denis!" : "Try again later, Denis...") << endl;
  }
  return 0;
}