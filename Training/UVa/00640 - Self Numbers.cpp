#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9, MX = 1e6;

int f(int x) {
  int ans = x;
  while (x > 0) {
    ans += x % 10;
    x /= 10;
  }
  return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
  vector<int> ans(MX + 1);
	fori(i, 0, MX + 1) {
    int x = f(i);
    if (x > MX) continue;
    ans[x] = 1;
  }
  fori(i, 0, MX + 1)
    if (ans[i] == 0)
      cout << i << endl;
	return 0;
}
