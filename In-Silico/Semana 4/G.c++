/*
 *  ITMOx Course - 3nd Week Problems
 *  Problem: K Best
 *  Level: Hard
 */
#include <bits/stdc++.h>
#define endl '\n'
#define EPS 1e-7
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

typedef pair<double, int> ii;

int n, k;
vector<ii> target;

void segmentSort(int left, int right, int k1, int k2) {
  double key = target[(left + right) / 2].first;
  int i = left, j = right;
  do {
    while (target[i].first > key)
      i++;
    while (key > target[j].first)
      j--;
    if (i <= j) {
      swap(target[i], target[j]);
      i++;
      j--;
    }
  } while (i <= j);
  if (left < j and k1 <= j) segmentSort(left, j, k1, k2);
  if (i < right and i <= k2) segmentSort(i, right, k1, k2);
}

bool can(vector<double> &v, vector<double> &w, double x) {
  for (int i = 0; i < target.size(); i++)
    target[i] = ii(v[i] - (x * w[i]), i);
  segmentSort(0, n - 1, 0, k);
  double acc = 0.0;
  for (int i = 0; i < k; i++)
    acc += target[i].first;
  return acc >= 0;
}

int main() {
  ios::sync_with_stdio(false);
  fin >> n >> k;
  target.resize(n);
  vector<double> value(n), weight(n);
  double maxval = -1.0;
  for (int i = 0; i < n; i++) {
    double v, w; fin >> v >> w;
    maxval = max(maxval, v / w);
    value[i] = v;
    weight[i] = w;
  }
  double lo = 0, hi = maxval;
  while (abs(hi - lo) > EPS) {
    double mid = (hi + lo) / 2;
    if (can(value, weight, mid))
      lo = mid;
    else
      hi = mid;
  }
  for (int i = 0; i < k; i++)
    fout << target[i].second + 1 << " ";
  fout << endl;
  return 0;
}