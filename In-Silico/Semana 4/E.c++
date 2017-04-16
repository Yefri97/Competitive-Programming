/*
 *  ITMOx Course - 3nd Week Problems
 *  Problem: Drying
 *  Level: Medium
 */
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int ceil(int a, int b) { return (a + b - 1) / b; }

bool check(vector<int> v, int k, int t) {
  for (int i = 0; i < v.size(); i++)
    v[i] = max(0, v[i] - t);
  for (int i = 0; i < v.size(); i++) {
    t -= ceil(v[i], k - 1);
    if (t < 0) return false;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  int n; fin >> n;
  vector<int> clothes(n);
  for (int i = 0; i < n; i++)
    fin >> clothes[i];
  int k; fin >> k;
  if (k == 1) {
    fout << *(max_element(clothes.begin(), clothes.end())) << endl;
  } else {
    int low = 1, high = *(max_element(clothes.begin(), clothes.end()));
    while (high - low > 1) {
      int mid = (high + low) / 2;
      if (check(clothes, k, mid))
        high = mid;
      else
        low = mid;
    }
    fout << high << endl;
  }
  return 0;
}