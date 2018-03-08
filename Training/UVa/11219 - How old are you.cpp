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
  int tc; cin >> tc;
  for (int t = 0; t < tc; t++) {
    string curr, date; cin >> curr >> date;
    string dd = curr.substr(0, 2), mm = curr.substr(3, 2), yyyy = curr.substr(6, 4);
    int d1 = stoi(dd), m1 = stoi(mm), y1 = stoi(yyyy);
    dd = date.substr(0, 2), mm = date.substr(3, 2), yyyy = date.substr(6, 4);
    int d0 = stoi(dd), m0 = stoi(mm), y0 = stoi(yyyy);
    int ans = y1 - y0;
    if (m1 < m0 || m1 == m0 && d1 < d0) ans--;
    cout << "Case #" << t + 1 << ": ";
    if (ans < 0)
      cout << "Invalid birth date" << endl;
    else if (ans > 130)
      cout << "Check birth date" << endl;
    else
      cout << ans << endl;
  }
	return 0;
}
