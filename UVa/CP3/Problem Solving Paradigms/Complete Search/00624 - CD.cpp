// Backtracking easy
#include <bits/stdc++.h>
using namespace std;

int n, k, maxSum;
vector<int> weight, ans, chosen;

void solver(int id, int curr) {
  if (id == n) {
    if (curr >= maxSum) {
      maxSum = curr;
      ans = chosen;
    }
  } else {
    if (curr + weight[id] > k) {
      solver(id + 1, curr);
    } else {
      solver(id + 1, curr);
      chosen.push_back(weight[id]);
      solver(id + 1, curr + weight[id]);
      chosen.pop_back();
    }
  }
}

int main() {
  while (cin >> k) {
    cin >> n;
    weight.assign(n, 0);
    for (int i = 0; i < n; i++)
      cin >> weight[i];
    maxSum = -1;
    solver(0, 0);
    for (int i = 0; i < ans.size(); i++)
      cout << ans[i] << " ";
    cout << "sum:" << maxSum << endl;
  }
  return 0;
}