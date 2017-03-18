#include <bits/stdc++.h>
using namespace std;

const int maxn = 40;

struct pos{
  int k, i, j;
  pos(int _k, int _i, int _j) { k = _k; i = _i; j = _j; }
};

int mk[10] = {0, 0, 0, 0, 1, -1};
int mi[10] = {1, 0, -1, 0, 0, 0};
int mj[10] = {0, 1, 0, -1, 0, 0};

char board[maxn + 10][maxn + 10][maxn + 10];
int l, r, c, in[5], out[5];

int bfs() {
  int d[maxn + 10][maxn + 10][maxn + 10]; d[in[0]][in[1]][in[2]] = 0;
  queue<pos> q; q.push(pos(in[0], in[1], in[2]));
  while (!q.empty()) {
    pos u = q.front(); q.pop();
    if (u.k == out[0] && u.i == out[1] && u.j == out[2]) return d[u.k][u.i][u.j];
    for (int i = 0; i < 6; i++) {
      pos v = pos(u.k + mk[i], u.i + mi[i], u.j + mj[i]);
      if (v.k < 0 || v.k >= l || v.i < 0 || v.i >= r || v.j < 0 || v.j >= c) continue;
      if (board[v.k][v.i][v.j] != '#') {
        board[v.k][v.i][v.j] = '#';
        d[v.k][v.i][v.j] = d[u.k][u.i][u.j] + 1;
        q.push(pos(v.k, v.i, v.j));
      }
    }
  }
  return -1;
}

int main() {
  while (cin >> l >> r >> c && l + r + c) {
    for (int k = 0; k < l; k++)
      for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) {
          char ch; cin >> ch;
          if (ch == 'S') { in[0] = k; in[1] = i; in[2] = j; }
          if (ch == 'E') { out[0] = k; out[1] = i; out[2] = j; }
          board[k][i][j] = ch;
        }
    int ans = bfs();
    if (ans == -1) cout << "Trapped!" << endl;
    else cout << "Escaped in " << ans << " minute(s)." << endl;
  }
  return 0;
}
