#include <bits/stdc++.h>
#define row(x) x / 5
#define col(x) x % 5
using namespace std;

const int kMaxN = 25, kINF = 1e9;

struct area { int i, j, v; };

int main() {
  int tc; cin >> tc;
  while (tc--) {
    vector<area> city;
    int n; cin >> n;
    while (n--) {
      area x; cin >> x.i >> x.j >> x.v;
      city.push_back(x);
    }
    int minV = kINF;
    vector<int> ans;
    for (int a = 0; a < kMaxN; a++) {
      for (int b = a + 1; b < kMaxN; b++) {
        for (int c = b + 1; c < kMaxN; c++) {
          for (int d = c + 1; d < kMaxN; d++) {
            for (int e = d + 1; e < kMaxN; e++) {
              int v = 0;
              for (int i = 0; i < city.size(); i++) {
                area curr = city[i];
                int minD = kMaxN + 1;
                minD = min(minD, (abs(row(a) - curr.i) + abs(col(a) - curr.j)));
                minD = min(minD, (abs(row(b) - curr.i) + abs(col(b) - curr.j)));
                minD = min(minD, (abs(row(c) - curr.i) + abs(col(c) - curr.j)));
                minD = min(minD, (abs(row(d) - curr.i) + abs(col(d) - curr.j)));
                minD = min(minD, (abs(row(e) - curr.i) + abs(col(e) - curr.j)));
                v += curr.v * minD;
              }
              if (v < minV) {
                int arr[] = {a, b, c, d, e};
                ans.assign(arr, arr + 5);
                minV = v;
              }
            }
          }
        }
      }
    }
    cout << ans[0] << " " << ans[1] << " " << ans[2] << " " << ans[3] << " " << ans[4] << endl;
  }
  return 0;
}