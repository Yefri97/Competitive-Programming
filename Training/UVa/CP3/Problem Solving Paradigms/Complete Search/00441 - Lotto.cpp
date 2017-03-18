// Three or More Nested Loops, Easy
#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 20;
int arr[MAX_N + 10];

int main() {
  int n, first = 1;
  while (cin >> n && n) {
    if (!first) cout << endl; first = 0;
    for (int i = 0; i < n; i++)
      cin >> arr[i];
    for (int a = 0; a < n; a++)
      for (int b = a + 1; b < n; b++)
        for (int c = b + 1; c < n; c++)
          for (int d = c + 1; d < n; d++)
            for (int e = d + 1; e < n; e++)
              for (int f = e + 1; f < n; f++)
                cout << arr[a] << " " << arr[b] << " " << arr[c] << " " << arr[d] << " " << arr[e] << " " << arr[f] << endl;
  }
  return 0;
}