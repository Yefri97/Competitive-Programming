/*
 *  RPC 11-th Contest 2016
 *  Problem F: Fusing trees
 *  Status: Accepted
 */

#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 10000;
int tree[MAX_N + 10][5];

int maxRoot(int id, int cont) {
  if (id == -1) return cont;
  return max(maxRoot(tree[id][0], cont + 1), maxRoot(tree[id][1], 0));
}

int main() {
  int n, m;
  while (cin >> n) {
    int id;
    for (int i = 0; i < n; i++) {
      int l, q; cin >> id >> l >> q; id--; l--; q--;
      tree[id][0] = q;
      tree[id][1] = l;
    }
    int mainRootLeft = 0;
    id = 0;
    while (id != -1) {
      id = tree[id][0];
      mainRootLeft++;
    }
    int maxRootLeft = maxRoot(0, 0);
    
    cin >> m;
    for (int i = 0; i < m; i++) {
      int id, q, r; cin >> id >> q >> r; id--; q--; r--;
      tree[id][0] = q;
      tree[id][1] = r;
    }
    int mainRootRight = 0;
    id = 0;
    while (id != -1) {
      id = tree[id][0];
      mainRootRight++;
    }
    int maxRootRight = maxRoot(0, 0);

    int ans = min(n + m - min(maxRootLeft, mainRootRight), n + m - min(mainRootLeft, maxRootRight));
    cout << ans << endl;

  }
  return 0;
}