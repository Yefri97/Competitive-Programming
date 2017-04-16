#include <bits/stdc++.h>
using namespace std;

vector<int> ans;

int solver(int n) {
  int f = 2;
  while (f * f <= n) {
    while (n % f == 0) { n /= f; ans.push_back(f); }
    f++;
  }
  if (n != 1) ans.push_back(n);
  return ans.size();
}

int main() {
  int n, k; cin >> n >> k;
  int numF = solver(n);
  if (numF < k) {
    cout << "-1" << endl; 
  } else {
    for (int i = 0; i < k - 1; i++)
      cout << ans[i] << " ";
    int x = 1;
    for (int i = k - 1; i < ans.size(); i++)
      x *= ans[i];
    cout << x << endl;
  }
  return 0;
}