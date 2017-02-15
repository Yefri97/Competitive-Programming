/*
 *  RPC 01st Contest 2017
 *  Problem J: Surf
 *  Status: Accepted
 */

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int main() {
  priority_queue<iii> pq;
  int n; cin >> n;
  while (n--) {
    int a, b, c; cin >> a >> b >> c;
    pq.push(iii(a, ii(b, c)));
  }
  int m = pq.top().first, mmax = -1, it = m;
  vector<int> best(m + 1);
  while (!pq.empty()) {
    iii tp = pq.top(); pq.pop();
    int t = tp.first, v = tp.second.first, w = tp.second.second;
    mmax = max(mmax, v + (t + w > m ? 0 : best[t + w]));
    best[t] = mmax;
    if (pq.empty()) continue;
    while (it > pq.top().first) best[it--] = mmax;
  }
  cout << mmax << endl;
  return 0;
}
