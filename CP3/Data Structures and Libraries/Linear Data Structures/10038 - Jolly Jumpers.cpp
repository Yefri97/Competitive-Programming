#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, v[3010];
  while (cin >> n) {
    for (int i = 0; i < n; i++)
      cin >> v[i];
    vector<int> cs(n - 1);
    int jolly = 1;
    for (int i = 1; i < n && jolly; i++) {
      int x = abs(v[i] - v[i - 1]); x--;
      if (x < 0 || x >= n - 1) 
        jolly = 0;
      else if (cs[x]) 
        jolly = 0;
      else
        cs[x] = 1;
    }
    if (jolly)
      cout << "Jolly" << endl;
    else
      cout << "Not jolly" << endl;
  }
  return 0;
}