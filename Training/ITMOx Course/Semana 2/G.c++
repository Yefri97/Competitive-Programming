/*
 *  ITMOx Course - 1st Week Problems
 *  Problem: Generate Tests!
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
  int ans = n, max_nd = -1;
  for (int a = 1, ia = 0; a <= n; ia++, a *= 2) {
    for (int b = a, ib = 0; ia >= ib && b <= n; ib++, b *= 3) {
      for (int c = b, ic = 0; ib >= ic && c <= n; ic++, c *= 5) {
        for (int d = c, id = 0; ic >= id && d <= n; id++, d *= 7) {
          for (int e = d, ie = 0; id >= ie && e <= n; ie++, e *= 11) {
            for (int g = e, ig = 0; ie >= ig && g <= n; ig++, g *= 13) {
              int num = g, nd = (ia + 1) * (ib + 1) * (ic + 1) * (id + 1) * (ie + 1) * (ig + 1);
              if (nd > max_nd) {
                max_nd = nd;
                ans = num;
              } else if (nd == max_nd) {
                ans = min(ans, num);
              }
            }
          }
        }
      }
    }
  }
  fout << n - ans + 1 << endl;
  return 0;
}