/*
 *  ITMOx Course - 1st Week Problems
 *  Problem: Put the Chairs the Right Way!
 *  Level: Easy
 */
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
  ios::sync_with_stdio(false);  // Fast input - output
  ifstream fin("input.txt");    // File Input
  ofstream fout("output.txt");  // File Output
  /*** Code ***/
  double a, b, c; fin >> a >> b >> c;
  double ans = (a + b + c) / 6.0;
  fout << fixed << ans << endl;
  return 0;
}