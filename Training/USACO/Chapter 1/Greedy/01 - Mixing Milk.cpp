/*
ID: yefri.g1
PROG: milk
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

int main() {
  ifstream fin ("milk.in");
  ofstream fout ("milk.out");
  int n, m; fin >> n >> m;
  vector<ii> farmers(m);
  for (int i = 0; i < m; i++) {
    int p, a; fin >> p >> a;
    farmers[i] = ii(p, a);
  }
  sort(farmers.begin(), farmers.end());
  int ans = 0;
  for (int i = 0; i < m and n; i++) {
    int p = farmers[i].first, a = farmers[i].second;
    int x = min(n, a);
    n -= x;
    ans += x * p;
  }
  fout << ans << endl;
  return 0;
}