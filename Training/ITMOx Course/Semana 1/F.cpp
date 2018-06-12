/*
 *  HackerRank - Warmup Challenges
 *  Problem: Plus Minus
 *  Level: Easy
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
  double n; cin >> n;
  double a = 0, b = 0, c = 0;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    if (x > 0) a++;
    if (x < 0) b++;
    if (x == 0) c++;
  }
  cout << fixed << setprecision(6);
  cout << a / n << endl;
  cout << b / n << endl;
  cout << c / n << endl;
  return 0;
}