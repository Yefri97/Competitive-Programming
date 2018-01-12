#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, k; cin >> n >> m >> k; m--;
  vector<int> price(n);
  for (int i = 0; i < n; i++)
    cin >> price[i];
  int l = m, r = m;
  while (l >= 0 and (price[l] == 0 or price[l] > k)) l--;
  while (r < n and (price[r] == 0 or price[r] > k)) r++;
  if (l < 0)
    cout << (r - m) * 10 << endl;
  else if (r >= n)
    cout << (m - l) * 10 << endl;
  else
    cout << min(m - l, r - m) * 10 << endl;
  return 0;
}