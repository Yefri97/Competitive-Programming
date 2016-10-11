#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e4, NUM_COINS = 5;
int coins[NUM_COINS + 10] = {50, 25, 10, 5, 1};
int memo[MAX_N + 10][NUM_COINS + 10];

int solver(int type, int value) {
  if (value == 0) return 1;
  if (value < 0) return 0;
  if (type == NUM_COINS) return 0;
  if (memo[value][type] != -1) return memo[value][type];
  int ans = solver(type, value - coins[type]) + solver(type + 1, value);
  return memo[value][type] = ans;
}

int main() {
  memset(memo, -1, sizeof memo);
  int n;
  while (cin >> n) {
    int ans = solver(0, n);
    cout << ans << endl;
  }
  return 0;
}