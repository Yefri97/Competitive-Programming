/*
 *  RPC 11-th Contest 2016
 *  Problem C: Containers
 *  Status: Accepted
 */

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef vector<int> vi;
typedef pair<int, vi> ii;

int mov[15][5] = {  {0, 1}, {1, 2}, {2, 3}, {4, 5}, {5, 6},
                    {6, 7}, {0, 4}, {1, 5}, {2, 6}, {3, 7} };

int dijkstra(vi s, vi t) {
  map<vi, int> dist; dist[s] = 0;
  priority_queue< ii, vector<ii>, greater<ii> > pq; pq.push(ii(0, s));
  while (!pq.empty()) {
    ii front = pq.top(); pq.pop();
    int d = front.first; vi u = front.second;
    if (d > dist[u]) continue;
    if (u == t) break;
    for (int i = 0; i < 10; i++) {
      vi v = u;
      swap(v[mov[i][0]], v[mov[i][1]]);
      int cost = v[mov[i][0]] + v[mov[i][1]];
      if (dist.count(v) == 0 || dist[u] + cost < dist[v]) {
        dist[v] = dist[u] + cost;
        pq.push(ii(dist[v], v));
      }
    }
  }
  return dist[t];
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  vi init(8), target(8);
  while (cin >> init[0]) {
    for (int i = 1; i < 8; i++)
      cin >> init[i];
    for (int i = 0; i < 8; i++)
      cin >> target[i];
    int ans = dijkstra(init, target);
    cout << ans << endl;
  }
  return 0;
}