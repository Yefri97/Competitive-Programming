// 1D Array Manipulation
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3000;
int input[MAXN + 10], arr[MAXN + 10];

int main() {
  int n;
  while (cin >> n) {
    for (int i = 0; i < n; i++)
      cin >> input[i];
    memset(arr, 0, sizeof arr);
    bool flag = 1;
    for (int i = 1; i < n; i++) {
      int x = abs(input[i] - input[i - 1]);
      if (x < 1 || x > n - 1 || arr[x])
        flag = 0;
      else
        arr[x] = 1;
    }
    cout << ((flag)? "Jolly" : "Not jolly") << endl;
  }
  return 0;
}