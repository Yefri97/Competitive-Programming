#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX_N = 100;
int n, arr[MAX_N + 10];
ll memo[MAX_N + 10][MAX_N + 10];

ll solver(int id, int k, int num) {
  if (k == 0) return 1;
  if (id == n) return 0;
  if (memo[id][k] != -1) return memo[id][k];
  ll cont = 0;
  for (int i = id; i < n; i++) {
    if (arr[i] > num) 
      cont += solver(i + 1, k - 1, arr[i]);
  }
  return memo[id][k] = cont;
}

int main() {
  int k;
  while (cin >> n >> k && (n + k)) {
    for (int i = 0; i < n; i++)
      cin >> arr[i];
    memset(memo, -1, sizeof memo);
    ll ans = solver(0, k, -1e5);
    cout << ans << endl;
  }
  return 0;
}