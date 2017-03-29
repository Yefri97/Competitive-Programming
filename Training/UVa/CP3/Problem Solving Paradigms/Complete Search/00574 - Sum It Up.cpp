// Recursive Backtracking (Medium)
#include <bits/stdc++.h>
using namespace std;

bool flag;
int k;
vector<int> ans, freq;

void solver(int sum, int id) {
  if (sum == k) {
    flag = true;
    for (int i = 0; i < ans.size(); i++) {
      if (i) cout << "+";
      cout << ans[i];
    }
    cout << endl;
  } else {
    for (int i = id; i > 0; i--) {
      if (freq[i] == 0 or sum + i > k) continue;
      freq[i]--;
      ans.push_back(i);
      solver(sum + i, i);
      freq[i]++;
      ans.pop_back();
    }
  }
}

int main() {
  int n;
  while (cin >> k >> n and (k or n)) {
    freq.assign(1010, 0);
    while (n--) {
      int x; cin >> x;
      freq[x]++;
    }
    flag = false;
    cout << "Sums of " << k << ":" << endl;
    solver(0, k);
    if (!flag) cout << "NONE" << endl;
  }
  return 0;
}
