#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

int g[10][10];
string ans;

void solver(int n, int u) {
  ans.push_back(u + '1');
  if (n == 0) {
    cout << ans << endl;
  } else {
    for (int i = 0; i < 5; i++) {
      if (g[u][i]) {
        g[u][i] = g[i][u] = 0;
        solver(n - 1, i);
        g[u][i] = g[i][u] = 1;
      }
    }
  }
  ans.pop_back();
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  g[0][1] = g[1][0] = 1;
  g[0][2] = g[2][0] = 1;
  g[0][4] = g[4][0] = 1;
  g[1][2] = g[2][1] = 1;
  g[1][4] = g[4][1] = 1;
  g[2][3] = g[3][2] = 1;
  g[2][4] = g[4][2] = 1;
  g[3][4] = g[4][3] = 1;
  solver(8, 0);
	return 0;
}
