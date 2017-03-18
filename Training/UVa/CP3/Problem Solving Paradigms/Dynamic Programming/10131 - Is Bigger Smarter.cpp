#include <bits/stdc++.h>
using namespace std;

struct e {
  int id, w, iq;
  e(int _id, int _w, int _iq) : id(_id), w(_w), iq(_iq) {}
  bool operator < (e other) const {
    return iq > other.iq;
  }
};

int main() {
  vector<e> ve;
  int n = 0, w, s;
  while (cin >> w >> s) ve.push_back(e(++n, w, s));
  sort(ve.begin(), ve.end());
  vector<int> lis(n, 1), path(n, -1);
  int mmax = 0, init = -1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (ve[i].w > ve[j].w && ve[i].iq != ve[j].iq) {
        if (lis[j] + 1 > lis[i]) {
          path[i] = j;
          lis[i] = lis[j] + 1;
        }
      }
    }
    if (lis[i] > mmax) {
      init = i;
      mmax = lis[i];
    }
  }
  vector<int> ans;
  for (int i = init; i != -1; i = path[i])
    ans.push_back(i);
  cout << mmax << endl;
  for (int i = ans.size() - 1; i >= 0; i--) 
    cout << ve[ans[i]].id << endl;
  return 0;
}