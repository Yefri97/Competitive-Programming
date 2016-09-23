#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e6 + 1;

int main() {
  vector<int> divisors(MAX_N, 1);
  for (int i = 2; i < MAX_N; i++)
    for (int j = i; j < MAX_N; j += i)
      divisors[j]++;

  int ans[MAX_N + 10]; ans[0] = 0;
  for (int i = 1; i < MAX_N; i++)
    ans[i] = (divisors[i] >= divisors[ans[i - 1]])? i : ans[i - 1];

  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    cout << ans[n] << endl;
  }
  return 0;
}