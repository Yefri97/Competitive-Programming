#include <bits/stdc++.h>
using namespace std;

struct state {
  int r1, c1, r2, c2;
  state() {}
  state(int _r1, int _c1, int _r2, int _c2) : r1(_r1), c1(_c1), r2(_r2), c2(_c2) {} 
};

int mi1[10] = { 0,  1,  0, -1};
int mj1[10] = {-1,  0,  1,  0};
int mi2[10] = { 0,  1,  0, -1};
int mj2[10] = { 1,  0, -1,  0};

const int MAX_N = 40, INF = -1;
int n, m, tr, tc;
int dist[MAX_N + 10][MAX_N + 10][MAX_N + 10][MAX_N + 10];
char board[MAX_N + 10][MAX_N + 10];

int bfs(state s) {
  for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) for (int k = 0; k < n; k++) for (int l = 0; l < m; l++)
    dist[i][j][k][l] = INF;
  dist[s.r1][s.c1][s.r2][s.c2] = 0;
  queue<state> q; q.push(s);
  while (!q.empty()) {
    state u = q.front(); q.pop();
    if (u.r1 == tr && u.r2 == tr && u.c1 == tc && u.c2 == tc) return dist[u.r1][u.c1][u.r2][u.c2];
    for (int i = 0; i < 4; i++) {
      state v = state(u.r1 + mi1[i], u.c1 + mj1[i], u.r2 + mi2[i], u.c2 + mj2[i]);
      if (v.r1 < 0 || v.r1 >= n || v.c1 < 0 || v.c1 >= m || board[v.r1][v.c1] == '#') {
        v.r1 = u.r1;
        v.c1 = u.c1;
      }
      if (v.r2 < 0 || v.r2 >= n || v.c2 < 0 || v.c2 >= m || board[v.r2][v.c2] == '#') {
        v.r2 = u.r2;
        v.c2 = u.c2;
      }
      if (dist[v.r1][v.c1][v.r2][v.c2] == INF) {
        dist[v.r1][v.c1][v.r2][v.c2] = dist[u.r1][u.c1][u.r2][u.c2] + 1;
        q.push(v);
      }
    }
  }
  return -1;
}

int main() {
  while (cin >> n >> m) {
    cin >> tr >> tc; tr--; tc--;
    int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2; r1--; c1--; r2--; c2--;
    state source = state(r1, c1, r2, c2);
    
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
      cin >> board[i][j];

    int ans = bfs(source);
    if (ans == -1) cout << "NO LOVE" << endl;
    else cout << ans << endl;
  }
  return 0;
}