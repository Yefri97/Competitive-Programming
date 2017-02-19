// Iterative, Two Nested loops
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  while (cin >> n >> m && n) {
    vector<double> front(n), rear(m);
    for (int i = 0; i < n; i++)
      cin >> front[i];
    for (int i = 0; i < m; i++)
      cin >> rear[i];

    vector<double> v;
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        v.push_back(rear[i] / front[j]);
    sort(v.begin(), v.end());

    double ans = -1;
    for (int i = 1; i < v.size(); i++) 
      ans = max(ans, v[i] / v[i - 1]);
    cout << fixed << setprecision(2) << ans << endl;
  }
  return 0;
}