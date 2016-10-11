#include <bits/stdc++.h>
using namespace std;

int main() {
  int t; cin >> t;
  while (t--) {
    int B, G, R; B = G = R = 0;
    int n; cin >> n;
    while (n--) {
      char a, b; cin >> a >> b;
      if (a == 'B') B += (b == 'G')? 1 : 2;
      if (a == 'G') G += (b == 'R')? 1 : 2;
      if (a == 'R') R += (b == 'B')? 1 : 2;
    }
    string ans;
    if (B == G && G == R)
      ans = "trempate";
    else if (B > G && B > R)
      ans = "blue";
    else if (G > B && G > R)
      ans = "green";
    else if (R > B && R > G)
      ans = "red";
    else
      ans = "empate";
    cout << ans << endl;
  }
  return 0;
}