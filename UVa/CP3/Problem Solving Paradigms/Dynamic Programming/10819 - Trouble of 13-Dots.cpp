#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100, INF = 1e7;
int k, n, weight[MAX_N + 10], value[MAX_N + 10], memo[110][10210];

int solver(int id, int val) {
  if (val > k && k <= 1800) return -INF;
  if (val > k + 200) return -INF;
  if (id == n) {
    if (val > k && val <= 2000) return -INF;
    return 0;
  }
  if (memo[id][val] != -1) return memo[id][val];
  return memo[id][val] = max(solver(id + 1, val + weight[id]) + value[id], solver(id + 1, val));
}

int main() {
  while (cin >> k >> n) {
    for (int i = 0; i < n; i++) 
      cin >> weight[i] >> value[i];
    memset(memo, -1, sizeof memo);
    int ans = solver(0, 0);
    cout << ans << endl;
  }  
  return 0;
}