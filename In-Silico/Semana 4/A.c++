/*
 *  ITMOx Course - 3nd Week Problems
 *  Problem: Sorting
 *  Level: Easy
 */
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

void mergeSort(int A[], int l, int r) {
  // Base case
  if (l + 1 == r) return;
  // Split
  int m = (l + r) / 2;
  mergeSort(A, l, m);
  mergeSort(A, m, r);
  // Merge
  int len = r - l, W[len + 5];
  for (int i = l, j = m, k = 0; i < m or j < r; k++) {
    if ((j == r) or (i < m and A[i] <= A[j])) {
      W[k] = A[i];
      i++;
    } else {
      W[k] = A[j];
      j++;
    }
  }
  for (int i = 0; i < len; i++)
    A[l + i] = W[i];
  fout << l + 1 << " " << r << " " << A[l] << " " << A[r - 1] << endl;
}

int main() {
  ios::sync_with_stdio(false);
  int n; fin >> n;
  int input[n + 5];
  for (int i = 0; i < n; i++)
    fin >> input[i];
  mergeSort(input, 0, n);
  for (int i = 0; i < n; i++)
    fout << input[i] << " ";
  fout << endl;
  return 0;
}