/*
 *  ITMOx Course - 3nd Week Problems
 *  Problem: Scarecrow Sort
 *  Level: Easy
 */
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

bool check(vector< vector<int> > &v) {
  vector<int> target;
  for (int j = 0; j < v[0].size(); j++) {
    for (int i = 0; i < v.size(); i++) {
      if (j == v[i].size()) break;
      target.push_back(v[i][j]);
    }
  }
  for (int i = 1; i < target.size(); i++)
    if (target[i - 1] > target[i])
      return false;
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  int n, k; fin >> n >> k;
  vector< vector<int> > v(k);
  for (int i = 0; i < n; i++) {
    int x; fin >> x;
    v[i % k].push_back(x);
  }
  for (int i = 0; i < v.size(); i++)
    sort(v[i].begin(), v[i].end());
  bool ans = check(v);
  fout << (ans ? "YES" : "NO") << endl;
  return 0;
}