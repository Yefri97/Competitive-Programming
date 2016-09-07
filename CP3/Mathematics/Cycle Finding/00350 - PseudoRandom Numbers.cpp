#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;

ll z, i, m;

ll f(ll x) { return (z * x + i) % m; }

ii floydCycleFinding(ll x0) {
  ll tortoise = f(x0), hare = f(f(x0));
  while (tortoise != hare) {
    tortoise = f(tortoise);
    hare = f(f(hare));
  }
  int mu = 0; hare = x0;
  while (tortoise != hare) {
    tortoise = f(tortoise);
    hare = f(hare);
    mu++;
  }
  int lamba = 1; hare = f(tortoise);
  while (tortoise != hare) {
    hare = f(hare);
    lamba++;
  }
  return ii(mu, lamba);
}

int main() {
  ll l;
  int cs = 0;
  while (cin >> z >> i >> m >> l && z + i + m + l) {
    cout << "Case " << ++cs << ": ";
    ii ans = floydCycleFinding(l);
    cout << ans.second << endl;
  }
  return 0;
}