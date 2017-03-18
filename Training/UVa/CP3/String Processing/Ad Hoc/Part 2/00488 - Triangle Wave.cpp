#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  while (n--) {
    int amp, frq; cin >> amp >> frq;
    for (int i = 0; i < frq; i++) {
      if (i) cout << endl;
      for (int j = 0; j < 2 * amp - 1; j++) {  
        for (int k = 0, stp = (j < amp)? j + 1 : 2 * amp - (j + 1); k < stp; k++) {
          if (j < amp)
            cout << j + 1;
          else
            cout << 2 * amp - (j + 1);
        }
        cout << endl;
      }
    }
    if (n) cout << endl;
  } 
  return 0;
}