#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

int lis(vi &v) {
  int n = v.size();
  vi lis(n, 1);
  fori(i, 0, n) {
    fori(j, 0, i) {
      if (v[i] > v[j])
        lis[i] = max(lis[i], lis[j] + 1);
    }
  }
  return *max_element(lis.begin(), lis.end());
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int x, tc = 0, f = 1;
  while (cin >> x && x != -1) {
    if (!f) cout << endl; f = 0;
    vi v;
    v.push_back(x);
    while (cin >> x && x != -1)
      v.push_back(x);
    reverse(v.begin(), v.end());
    int ans = lis(v);
    cout << "Test #" << ++tc << ":" << endl;
    cout << "  maximum possible interceptions: " << ans << endl;
  }
	return 0;
}
