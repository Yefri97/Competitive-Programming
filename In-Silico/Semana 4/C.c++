/*
 *  ITMOx Course - 3nd Week Problems
 *  Problem: Anti-Quicksort
 *  Level: Easy
 */
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  ios::sync_with_stdio(false);
  int n; fin >> n;
  vector<int> ans(n);
  ans[0] = 1;
  if (n > 1) ans[1] = 2;
  for (int i = 2; i < n; i++) {
    ans[i] = ans[i / 2];
    ans[i / 2] = i + 1;
  }
  for (int i = 0; i < n; i++)
    fout << ans[i] << " ";
  fout << endl;
  return 0;
}