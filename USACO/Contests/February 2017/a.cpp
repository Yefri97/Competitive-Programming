/*
ID: yefri97
PROG: helpcross
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, int> event;

int main() {
  ifstream fin ("helpcross.in");
  ofstream fout ("helpcross.out");
  set<event> sl;
  int n, m; fin >> n >> m;
  for (int i = 0; i < n; i++) {
    int x; fin >> x;
    sl.insert(event(ii(x, 1), i));
  }
  vector<ii> v(m);
  for (int i = 0; i < m; i++) {
    fin >> v[i].first >> v[i].second;
    sl.insert(event(ii(v[i].first, 0), i));
    sl.insert(event(ii(v[i].second, 2), i));
  }
  int ans = 0;
  priority_queue<ii, vector<ii>, greater<ii> > pq;
  for (set<event>::iterator it = sl.begin(); it != sl.end(); it++) {
    event e = *it;
    int tm = e.first.first, tp = e.first.second, id = e.second;
    if (tp == 1) {
      if (!pq.empty()) {
        ii top = pq.top(); pq.pop();
        int a = top.first, b = top.second;
        sl.erase(sl.find(event(ii(a, 2), b)));
        ans++;
      }
    } else {
      if (tp == 0) {
        pq.push(ii(v[id].second, id));
      } else {
        pq.pop();
      }
    }
  }
  fout << ans << endl;
  return 0;
}