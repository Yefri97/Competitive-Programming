#include <bits/stdc++.h>
using namespace std;


int main() {
  int n, m[110][110];
  while (cin >> n && n) {
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        cin >> m[i][j];
    int row = -1, col = -1, flag = 1;
    for (int i = 0; i < n; i++) {
      int cont = 0;
      for (int j = 0; j < n; j++) {
        cont += m[i][j];
      }
      if (cont % 2) {
        if (row == -1)
          row = i;
        else
          flag = 0;
      }
    }
    for (int i = 0; i < n; i++) {
      int cont = 0;
      for (int j = 0; j < n; j++) {
        cont += m[j][i];
      }
      if (cont % 2) {
        if (col == -1)
          col = i;
        else
          flag = 0;
      }
    }
    if (flag)
      if (row == -1 && col == -1)
        cout << "OK" << endl;
      else
        cout << "Change bit (" << row + 1 << "," << col + 1 << ")" << endl;
    else
      cout << "Corrupt" << endl;
  }
  return 0;
}