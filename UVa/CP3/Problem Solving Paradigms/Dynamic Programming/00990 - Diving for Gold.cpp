#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 30, MAX_T = 1000;
int n, w, depth[MAX_N + 10], value[MAX_N + 10], memo[MAX_N + 10][MAX_T + 10];

int solver(int id, int t) {
  if (id == n) return memo[id][t] = 0;
  if (memo[id][t] != -1) return memo[id][t];
  int cost = 3 * w * depth[id];
  if (cost > t) return memo[id][t] = solver(id + 1, t);
  return memo[id][t] = max(solver(id + 1, t), solver(id + 1, t - cost) + value[id]);
}

int main() {
  int t, first = 1;
  while (cin >> t >> w) {
    if (!first) cout << endl; first = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> depth[i];
      cin >> value[i];
    }
    memset(memo, -1, sizeof memo);
    int mv = solver(0, t), nt = 0;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
      int cost = 3 * w * depth[i];
      if (cost > t) continue;
      if (memo[i + 1][t - cost] + value[i] > memo[i + 1][t]) {
        ans.push_back(i);
        t -= cost;
        nt++;
      }
    }
    cout << mv << endl;
    cout << nt << endl;
    for (int i = 0; i < ans.size(); i++)
      cout << depth[ans[i]] << " " << value[ans[i]] << endl;
  }
  return 0;
}