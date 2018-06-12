/*
 *  ITMOx Course - 1st Week Problems
 *  Problem: Win the Competition!
 *  Level: Easy
 */
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MAX_N = 15;
int n, arr[MAX_N + 10];

int solver(int id, int val) {
  if (id == n) return 0;
  if (arr[id] > val) return solver(id + 1, val);
  return max(solver(id + 1, val), solver(id + 1, val - arr[id]) + 1);
}

int main() {
  ios::sync_with_stdio(false);  // Fast input - output
  ifstream fin("input.txt");    // File Input
  ofstream fout("output.txt");  // File Output
  /*** Code ***/
  fin >> n;
  for (int i = 0; i < n; i++)
    fin >> arr[i];
  int ans = solver(0, 18000);
  fout << ans << endl;
  return 0;
}