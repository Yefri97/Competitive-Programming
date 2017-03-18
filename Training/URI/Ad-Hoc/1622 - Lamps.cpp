#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

int n, k;

int f(int x) { return (x + k) % n; }

ii floydCicleFinding(int x0) {
  int tortoise = f(x0), hare = f(f(x0));
  while (tortoise != hare) { tortoise = f(tortoise); hare = f(f(hare)); }
  int mu = 0; hare = x0;
  while (tortoise != hare) { tortoise = f(tortoise); hare = f(hare); mu++; }
  int lambda = 1; hare = f(tortoise);
  while (tortoise != hare) { hare = f(hare); lambda++; }
  return ii(mu, lambda);
}

int main() {
  int q;
  while (cin >> n >> q && (n + q)) {
    string line; cin >> line;
    while (q--) {
      int m; cin >> k >> m;
      string s = line;
      ii cf = floydCicleFinding(0);
      int mu = cf.first, lambda = cf.second;
      
      int it = 0;
      while (mu--) {
        s[it] = (s[it] == 'x')? 'o' : 'x';
        it = f(it);
      }

      int x = m / lambda, r = m % lambda;
      while (lambda--) {
        s[it] = (x % 2)? ((s[it] == 'x')? 'o' : 'x') : s[it];
        it = f(it);
      }
      while (r--) {
        s[it] = (s[it] == 'x')? 'o' : 'x';
        it = f(it);
      }

      cout << s << endl;
    }
  }
  return 0;
}