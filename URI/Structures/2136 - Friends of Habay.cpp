#include <bits/stdc++.h>
using namespace std;
typedef pair<int, string> ii;

int main() {
  set<ii> s;
  string a, b;
  string ans;
  while (cin >> a >> b && a != "FIM") {
    if (b == "YES") {
      s.insert(ii(0, a));
      if (a.size() > ans.size()) ans = a;
    } else {
      s.insert(ii(1, a));
    }
  }
  for (set<ii>::iterator it = s.begin(); it != s.end(); it++)
    cout << (*it).second << endl;
  cout << endl;
  cout << "Amigo do Habay:" << endl;
  cout << ans << endl;
  return 0;
}