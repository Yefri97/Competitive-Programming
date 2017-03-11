/*
 *  HackerRank - Warmup Challenges
 *  Problem: Compare the Triplets
 *  Level: Easy
 */
#include <bits/stdc++.h>
using namespace std;

const int k = 3;

int main() {
  int a[k], b[k];
  for (int i = 0; i < k; i++)
    cin >> a[i];
  for (int i = 0; i < k; i++)
    cin >> b[i];
  int ans[10]; ans[0] = ans[1] = 0;
  for (int i = 0; i < k; i++) {
    if (a[i] == b[i]) continue;
    if (a[i] > b[i]) ans[0]++;
    else ans[1]++;
  }
  cout << ans[0] << " " << ans[1] << endl;
  return 0;
}