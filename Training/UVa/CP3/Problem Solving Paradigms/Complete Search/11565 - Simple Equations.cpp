#include <bits/stdc++.h>
using namespace std;

int main() {
  int tc; cin >> tc;
  while (tc--) {
    int A, B, C; cin >> A >> B >> C;
    int x, y, z;
    bool done = false;
    for (x = -100; x <= 100; x++)
      for (y = -100; y <= 100; y++)
        for (z = -100; z <= 100; z++)
          if (!done and x != y and x != z and y != z and
              x + y + z == A and x * y * z == B and x * x + y * y + z * z == C) {
            cout << x << " " << y << " " << z << endl;
            done = true;
          }
    if (!done)
      cout << "No solution." << endl;
  }
  return 0;
}