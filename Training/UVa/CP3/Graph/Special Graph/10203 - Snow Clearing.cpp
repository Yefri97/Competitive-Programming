#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))
#define sq(x) (x) * (x)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int oo = 1e9;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout << setfill('0');
  int t; cin >> t;
  string s;
  getline(cin, s); getline(cin, s);
  while (t--) {
    double d = 0;
    getline(cin, s);
    while (getline(cin, s) && s.size()) {
      stringstream ss(s);
      double x1, x2, y1, y2;
      ss >> x1 >> y1 >> x2 >> y2;
      d += pow(sq(x1 - x2) + sq(y1 - y2), 0.5);
    }
    int ans = round(d * 2 * 60 / 20000);
    cout << ans / 60 << ":" << setw(2) << ans % 60 << endl;
    if (t) cout << endl;
  }
  return 0;
}