/*
 *  ITMOx Course - 3nd Week Problems
 *  Problem: Fence Painting
 *  Level: Medium
 */
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

bool can(vector<int> &v, int k, int x) {
  for (int i = 0; i < v.size(); i++) {
    if (k - i * x - v[i] < 0)
      return false;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  int n, k; fin >> n >> k;
  vector<int> friends(n);
  for (int i = 0; i < n; i++)
    fin >> friends[i];
  sort(friends.rbegin(), friends.rend());
  int lo = 0, hi = friends[n - 1] + 1;
  while (hi - lo > 1) {
    int mid = (hi + lo) / 2;
    if (can(friends, k, mid))
      lo = mid;
    else
      hi = mid;
  }
  fout << lo << endl;
  return 0;
}