/*
 *  ITMOx Course - 1st Week Problems
 *  Problem: Prepare Yourself to Competitions!
 *  Level: Easy
 */
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int kInf = 1e6;
  
int main() {
  ios::sync_with_stdio(false);  // Fast input - output
  ifstream fin("input.txt");    // File Input
  ofstream fout("output.txt");  // File Output
  /*** Code ***/
  int n; fin >> n;
  vector<int> practice(n);
  for (int i = 0; i < n; i++)
    fin >> practice[i];
  vector<int> theory(n);
  for (int i = 0; i < n; i++)
    fin >> theory[i];
  int ans = 0;
  bool p = false, t = false;
  for (int i = 0; i < n; i++) {
    if (practice[i] > theory[i]) {
      ans += practice[i];
      p = true;
    } else {
      ans += theory[i];
      t = true;
    }
  }
  if (!p or !t) {
    int mmin = kInf;
    for (int i = 0; i < n; i++)
      mmin = min(mmin, abs(practice[i] - theory[i]));
    ans -= mmin;
  }
  fout << ans << endl;
  return 0;
}