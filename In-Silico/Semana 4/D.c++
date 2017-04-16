/*
 *  ITMOx Course - 3nd Week Problems
 *  Problem: K-th Ordered Statistic
 *  Level: Easy
 */
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

const int kMaxN = 40000000;
int seq[kMaxN];

// QuickSort modified
void segmentSort(int left, int right, int k1, int k2) {
  int key = seq[(left + right) / 2];
  int i = left, j = right;
  do {
    while (seq[i] < key)
      i++;
    while (key < seq[j])
      j--;
    if (i <= j) {
      swap(seq[i], seq[j]);
      i++;
      j--;
    }
  } while (i <= j);
  if (left < j and k1 <= j) segmentSort(left, j, k1, k2);
  if (i < right and k2 >= i) segmentSort(i, right, k1, k2);
}

int main() {
  ios::sync_with_stdio(false);
  int n, k1, k2; fin >> n >> k1 >> k2;
  int A, B, C; fin >> A >> B >> C;
  fin >> seq[0] >> seq[1];
  for (int i = 2; i < n; i++)
    seq[i] = A * seq[i - 2] + B * seq[i - 1] + C;
  segmentSort(0, n - 1, k1 - 1, k2 - 1);
  for (int i = k1 - 1; i <= k2 - 1; i++)
    fout << seq[i] << " ";
  fout << endl;
  return 0;
}