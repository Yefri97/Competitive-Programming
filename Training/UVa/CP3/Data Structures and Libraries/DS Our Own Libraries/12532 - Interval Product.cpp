// Tree-related Data Structures
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define LSOne(S) (S & (-S))

class FenwickTree {
private:
  vi ft;

public:
  FenwickTree() {}
  FenwickTree(int n) { ft.assign(n + 1, 0); }

  int rsq(int b) {
    int sum = 0; 
    for (; b; b -= LSOne(b)) 
      sum += ft[b];
    return sum;
  }

  int rsq(int a, int b) { return rsq(b) - (a == 1 ? 0 : rsq(a - 1)); }

  void adjust(int k, int v) {
    for (; k < (int)ft.size(); k += LSOne(k)) 
      ft[k] += v;
  }
};

int main() {
  int n, q;
  while (cin >> n >> q) {
    FenwickTree sumFt(n), zeroFt(n);
    for (int i = 0; i < n; i++) {
      int x; cin >> x;
      if (x == 0) zeroFt.adjust(i + 1, 1);
      if (x < 0) sumFt.adjust(i + 1, 1);
    }
    while (q--) {
      char c; cin >> c;
      if (c == 'C') {
        int pos, value; cin >> pos >> value;
        if (zeroFt.rsq(pos, pos)) {
          if (value) {
            zeroFt.adjust(pos, -1);
            sumFt.adjust(pos, (value < 0) - sumFt.rsq(pos, pos));
          }
        } else {
          if (value) {
            sumFt.adjust(pos, (value < 0) - sumFt.rsq(pos, pos));
          } else {
            zeroFt.adjust(pos, 1);
            sumFt.adjust(pos, -sumFt.rsq(pos, pos));
          }
        }
      } else {
        int i, j; cin >> i >> j;
        if (zeroFt.rsq(i, j)) cout << "0";
        else cout << ((sumFt.rsq(i, j) % 2) ? "-" : "+");
      }
    }
    cout << endl;
  }
  return 0;
}