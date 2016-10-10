#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, cs = 0; cin >> n;
  while (n--) {
    cout << "Case " << ++cs << ": ";
    int a, b, c, d, e, f, g; cin >> a >> b >> c >> d >> e >> f >> g;
    int cont = a + b + c + d;
    vector<int> v = {e, f, g};
    sort(v.rbegin(), v.rend());
    cont += (v[0] + v[1]) / 2;
    char ans;
    if (cont < 60)
      ans = 'F';
    else if (cont < 70)
      ans = 'D';
    else if (cont < 80)
      ans = 'C';
    else if (cont < 90)
      ans = 'B';
    else
      ans = 'A';
    cout << ans << endl;
  }
  return 0;
}