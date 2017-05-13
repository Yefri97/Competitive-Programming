/*
ID: yefri.g1
PROG: barn1
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
  ifstream fin ("barn1.in");
  ofstream fout ("barn1.out");
  int m, s, c; fin >> m >> s >> c;
  vector<int> seq(c);
  for (int i = 0; i < c; i++)
    fin >> seq[i];
  sort(seq.begin(), seq.end());
  priority_queue<int> pq;
  for (int i = 1; i < c; i++) {
    if (seq[i] - seq[i - 1] > 1)
      pq.push(-(seq[i] - seq[i - 1] - 1));
  }
  int ans = c;
  while (pq.size() + 1 > m) {
    ans += -pq.top(); pq.pop();
  }
  fout << ans << endl;
  return 0;
}