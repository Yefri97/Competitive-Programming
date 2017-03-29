// Recursive Backtracking (Harder)
#include <bits/stdc++.h>
using namespace std;

int k, cont;
string ans;
vector< vector<bool> > flagA, flagB;

bool solver(int id) {
  if (id == 5) {
    cont++;
    if (cont == k) {
      cout << ans << endl;
      return true;
    }
    return false;
  }
  for (int i = 0; i < 26; i++) {
    if (flagA[id][i] and flagB[id][i]) {
      ans[id] = i + 'A';
      if (solver(id + 1)) return true;
    }
  }
  return false;
}

int main() {
  int tc; cin >> tc;
  while (tc--) {
    cont = 0;
    cin >> k;
    vector< vector<char> > A(6, vector<char>(5)), B(6, vector<char>(5));
    for (int i = 0; i < 6; i++)
      for (int j = 0; j < 5; j++)
        cin >> A[i][j];
    for (int i = 0; i < 6; i++)
      for (int j = 0; j < 5; j++)
        cin >> B[i][j];
    flagA.assign(5, vector<bool>(26));
    flagB.assign(5, vector<bool>(26));
    for (int i = 0; i < 5; i++)
      for (int j = 0; j < 6; j++)
        flagA[i][A[j][i] - 'A'] = true;
    for (int i = 0; i < 5; i++)
      for (int j = 0; j < 6; j++)
        flagB[i][B[j][i] - 'A'] = true;
    ans.assign(5, ' ');
    if (!solver(0))
      cout << "NO" << endl;
  }
  return 0;
}