/*
 *  ITMOx Course - 2nd Week Problems
 *  Problem: Snowmen
 *  Level: Medium
 */
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
  ios::sync_with_stdio(false);  // Fast input - output
  ifstream fin("input.txt");    // File Input
  ofstream fout("output.txt");  // File Output
  /*** Code ***/
  int n; fin >> n;
  vector<int> p(n + 1), acc(n + 1);
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    int t, m; fin >> t >> m;
    if (m > 0) {
      p[i] = t;
      ans += acc[i] = m + acc[t];
    } else {
      p[i] = p[p[t]];
      ans += acc[i] = acc[p[t]];
    }
  }
  fout << ans << endl;
  return 0;
}