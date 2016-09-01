#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<string> vs;
  int mmax = -1;
  string line;
  while (getline(cin, line)) {
    vs.push_back(line);
    mmax = max(mmax, (int) line.size());
  }
  for (int i = 0; i < mmax; i++) {
    for (int j = 0; j < vs.size(); j++) {
      if (i < vs[vs.size() - j - 1].size())
        cout << vs[vs.size() - j - 1][i];
      else
        cout << " ";
    }
    cout << endl;
  }
  return 0;
}