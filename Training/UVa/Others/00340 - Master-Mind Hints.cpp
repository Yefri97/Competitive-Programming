#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, tc = 0;
  while (cin >> n && n != 0) {
    vector<int> s(n), cnts(10);
    fori(i, 0, n) {
      int x; cin >> x;
      s[i] = x;
      cnts[x]++;
    }
    cout << "Game " << ++tc << ":" << endl;
    while (true) {
      vector<int> g(n), cntg(10);
      fori(i, 0, n) {
        int x; cin >> x;
        g[i] = x;
        cntg[x]++;
      }
      if (cntg[0] == n) break;
      int strong = 0;
      fori(i, 0, n)
        strong += (s[i] == g[i]);
      int match = 0;
      fori(i, 1, 10)
        match += min(cnts[i], cntg[i]);
      cout << "    (" << strong << "," << match - strong << ")" << endl;
    }
  }
	return 0;
}
