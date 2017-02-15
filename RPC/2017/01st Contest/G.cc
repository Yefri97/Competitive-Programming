/*
 *  RPC 01st Contest 2017
 *  Problem G: Grid
 *  Status: Accepted
 */

#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cout << #x << ": " << x << endl
#define endl '\n'
const int MX = 505;
int board[MX][MX], n, m;
int mx[] = {1, 0, -1, 0};
int my[] = {0, 1, 0, -1};
bool vi[MX][MX];

struct state{
  int x, y, d;
  state(){}
  state(int _x, int _y, int _d): x(_x), y(_y), d(_d){}
};

bool check(int x, int y) {
  if (x >= 0 && x < n && y >= 0 && y < m && !vi[x][y])
    return true;
  return false;
}

void solve() {
  queue<state> Q;
  Q.push(state(0, 0, 0));
  vi[0][0] = true;
  while (!Q.empty()) {
    state st = Q.front();
    Q.pop();
    if (st.x + 1 == n && st.y + 1 == m) {
      cout << st.d << endl; return;
    }
    for (int i = 0; i < 4; i++) {
      int au = board[st.x][st.y];
      int xt = st.x + mx[i] * au;
      int yt = st.y + my[i] * au;
      if (check(xt, yt)) {
        vi[xt][yt] = true;
        Q.push(state(xt, yt, st.d + 1));
      }
    }
  }
  cout << "IMPOSSIBLE" << endl;
  return;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  char c;
  while (cin >> n >> m) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> c;
        board[i][j] = c - '0';
      }
    }
    memset(vi, 0,sizeof vi);
    solve();
  }
}
