// Graph Data Structures
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

int main() {
  int n, m; 
  while (cin >> n >> m) {
    vector< vector<ii> > transMatrix(m);
    for (int i = 0; i < n; i++) {
      int r, c; cin >> r;
      vector<int> col(r);
      for (int j = 0; j < r; j++) cin >> col[j];
      for (int j = 0; j < r; j++) {
        int a; cin >> a;
        transMatrix[col[j]-1].push_back(ii(a, i));
      }
    }
    cout << m << " " << n << endl;
    for (int i = 0; i < m; i++) {
      cout << transMatrix[i].size();
      for (int j = 0; j < transMatrix[i].size(); j++)
        cout << " " << transMatrix[i][j].second+1;
      cout << endl;
      for (int j = 0; j < transMatrix[i].size(); j++) {
        if (j) cout << " ";
        cout << transMatrix[i][j].first;
      }
      cout << endl;
    }
  }
  return 0;
}