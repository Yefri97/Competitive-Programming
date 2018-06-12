/*
 *  ITMOx Course - 3nd Week Problems
 *  Problem: Inversions
 *  Level: Easy
 */
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

long long inversions(int A[], int l, int r) {
  // Base case
  if (l + 1 == r) return 0;
  // Split
  long long target = 0;
  int m = (l + r) / 2;
  target += inversions(A, l, m);
  target += inversions(A, m, r);
  // Merge
  int len = r - l, W[len + 5];
  for (int i = l, j = m, k = 0; i < m or j < r; k++) {
    if (j == r or (i < m and A[i] <= A[j])) {
      W[k] = A[i];
      i++;
    } else {
      W[k] = A[j];
      j++;
      target += m - i;
    }
  }
  for (int i = 0; i < len; i++)
    A[l + i] = W[i];
  return target;
}

int main() {
  ios::sync_with_stdio(false);
  int n; fin >> n;
  int input[n + 5];
  for (int i = 0; i < n; i++)
    fin >> input[i];
  long long ans = inversions(input, 0, n);
  fout << ans << endl;
  return 0;
}