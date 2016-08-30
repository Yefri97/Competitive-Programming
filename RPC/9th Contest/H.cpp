/*
 *  RPC 9-th Contest 2016
 *  Problem H: Positively Pentastic!
 *  Status: Accepted
 */

#include <bits/stdc++.h>
using namespace std;

int mod(int n, int m) {
  return (n % m + m) % m;
}

int main() {
    int n, cs = 0; cin >> n;
    while (n--) {
        cout << "Pentagon #" << ++cs << ":" << endl;
        int v[6];
        for (int i = 0; i < 5; i++) cin >> v[i];
        while (true) {
          int mmin = 1000, id = 0;
          for (int i = 0; i < 5; i++) if (v[i] < mmin) {
            mmin = v[i];
            id = i;
          }
          if (!(mmin < 0)) break;
          v[mod(id + 1, 5)] += v[id];
          v[mod(id - 1, 5)] += v[id];
          v[id] = abs(v[id]);
        }
        for (int i = 0; i < 5; i++) {
          if (i) cout << " ";
          cout << v[i];
        }
        cout << endl;
    }
    return 0;
}