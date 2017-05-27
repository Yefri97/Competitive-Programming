#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl;
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int INF = 1e9;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  ll x1, y1; cin >> x1 >> y1;
  ll x2, y2; cin >> x2 >> y2;
  ll xc, yc; cin >> xc >> yc;
  ll w = min(xc - x1, x2 - xc);
  ll h = min(yc - y1, y2 - yc);
  ll width = 2 * w + 1, height = 2 * h + 1;
  ll area = width * height;
  cout << (area - 1) / 2 << endl;
  return 0;
}