#include <bits/stdc++.h>

using namespace std;

struct pos{
  int ori, i, j;
  pos(int _ori, int _i, int _j) { ori = _ori; i = _i; j = _j; }
};

int mi[5] = {0, -1, 0, 1};
int mj[5] = {-1, 0, 1, 0};

int n, m[2100][2100][5];
char board[2100][2100];

int mod(int n, int m) { return ((n % m) + m) % m; }

int bfs(int oo, int io, int jo) {
  memset(m, -1, sizeof m);
  m[io][jo][oo] = 0;
  deque<pos> q; q.push_front(pos(oo, io, jo));
  while (!q.empty()) {
    pos u = q.front(); q.pop_front();
    pos v = pos((u.ori + 2) % 4, u.i + mi[u.ori], u.j + mj[u.ori]);
    if (!(v.i < 0 || v.i >= n || v.j < 0 || v.j >= n)) {
	    if (m[v.i][v.j][v.ori] == -1) {
	      m[v.i][v.j][v.ori] = m[u.i][u.j][u.ori];
	      q.push_front(v);
	    }
	}
    v = pos(mod(((board[u.i][u.j] == 'H')? u.ori + 1 : u.ori - 1), 4), u.i, u.j);
    if (m[v.i][v.j][v.ori] == -1) {
      m[v.i][v.j][v.ori] = m[u.i][u.j][u.ori] + 1;
      q.push_back(v);
    }
  }
  //for (int i = 0; i <= n; i++) { for (int j = 0; j <= n; j++) cout << m[i][j][2] << " "; cout << endl; }
  return m[n - 1][n - 1][2];
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) 
    for (int j = 0; j < n; j++) 
      cin >> board[i][j];
  int ans = bfs(0, 0, 0);
  cout << ans << endl;
  return 0;
}