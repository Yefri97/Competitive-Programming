/*
 *  HackerRank - Warmup Challenges
 *  Problem: Mini-Max Sum
 *  Level: Easy
 */
#include <bits/stdc++.h>
using namespace std;

const int k = 5;

int main() {
  long long x;
  cin >> x;
  long long low = x, high = x, acc = x;
  for (int i = 1; i < k; i++) {
    cin >> x;
    acc += x;
    low = min(low, x);
    high = max(high, x);
  }
  cout << acc - high << " " << acc - low << endl;
  return 0;
}