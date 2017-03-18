#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

int n;
int f(int x) {
  long long temp = (long long) x * x;
  string s = to_string(temp);
  if (s.size() > n)
    s = s.substr(0, n);
  return atoi(s.c_str());
}

ii floydCicleFinding(int x0) {
  int tortoise = f(x0), hare = f(f(x0));
  while (tortoise != hare) { tortoise = f(tortoise); hare = f(f(hare)); }
  int mu = 0; hare = x0;
  while (tortoise != hare) { tortoise = f(tortoise); hare = f(hare);  mu++; }
  int lambda = 1; hare = f(tortoise);
  while (tortoise != hare) { hare = f(hare); lambda++; }
  return ii(mu, lambda);
}

int main() {
  int t; cin >> t;
  while (t--) {
    int k; cin >> n >> k;
    ii u = floydCicleFinding(k);
    int mu = u.first, lambda = u.second;
    int ans = -1;
    for (int i = 0; i < mu + lambda; i++, k = f(k))
      ans = max(ans, k);
    cout << ans << endl;
  }
  return 0;
}