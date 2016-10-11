#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 17;

int main() {
  long long seq[MAX_N + 10];
  seq[0] = 0; seq[1] = 1;
  for (int i = 2; i < MAX_N; i++)
    seq[i] = (i % 2)? seq[i - 1] * seq[i - 2] : seq[i - 1] + seq[i - 2];
  int n;
  while (cin >> n) {
    cout << seq[n - 1] << endl;
  }
  return 0;
}