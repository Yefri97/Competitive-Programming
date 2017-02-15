/*
 *  RPC 10-th Contest 2016
 *  Problem G: Generate, Sort and Search
 *  Status: Accepted
 */

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

const int MXN = 1e3;
int a, c, m;

int f(int x) { return (a * x + c) % m; }

ii floydCycleFinding(int x0) {
  int tortoise = f(x0), hare = f(f(x0));
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
  int x, q, n;
  while (cin >> a >> c >> m >> x >> q >> n) {
    int cs[MXN + 10]; memset(cs, 0, sizeof cs);
    ii u = floydCycleFinding(x);
    int mu = u.first, lamba = u.second;

    for (int i = 0; i < mu; i++, x = f(x))
      cs[x]++;
    
    int ka = (n - mu) / lamba, kb = (n - mu) % lamba;
    for (int i = 0; i < lamba; i++, x = f(x))
      cs[x] += ka + (i < kb);
    
    vector<int> freq(m); freq[0] = cs[0];
    for (int i = 1; i < m; i++)
      freq[i] = freq[i - 1] + cs[i];

    while (q--) {
      int nq; cin >> nq;
      int lo = 0, hi = m - 1;
      while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (freq[mid] < nq)
          lo = mid + 1;
        else
          hi = mid - 1;
      }
      if (freq[lo] < nq) lo++;
      cout << lo << endl;
    }
  }

  return 0;
}