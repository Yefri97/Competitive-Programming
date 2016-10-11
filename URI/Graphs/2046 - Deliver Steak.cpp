#include <bits/stdc++.h>
using namespace std;

struct point{
  int i, j;

  point(int _i, int _j) : i(_i), j(_j) {}

  bool operator < (point other) const {
    if (i != other.i)
      return i < other.i;
    return j < other.j;
  }
};

typedef pair<point, int> ii;
const int MAX_N = 1000;
int m, n, board[MAX_N + 10][MAX_N + 10];

int mi[5] = {-1, 0, 1, 0};
int mj[5] = {0, 1, 0, -1};

vector<point> hq;

void bfs() {
  queue<ii> q;
  for (int id = 0; id < hq.size(); id++) {
    board[hq[id].i][hq[id].j] = id;
    q.push(ii(hq[id], id));
  }
  while (!q.empty()) {
    ii front = q.front(); q.pop();
    point u = front.first; int id = front.second;
    for (int i = 0; i < 4; i++) {
      point v = point(u.i + mi[i], u.j + mj[i]);
      if (v.i >= m || v.i < 0 || v.j >= n || v.j < 0) continue;
      if (board[v.i][v.j] == -1) {
        board[v.i][v.j] = id;
        q.push(ii(v, id));
      }
    }
  }
}

int main() {
  int cs = 0;
  while (cin >> m >> n && m * n) {
    if (cs) cout << endl;
    cout << "Instancia " << ++cs << endl;
    hq.clear();
    int k; cin >> k;
    while (k--) {
      int x, y; cin >> x >> y; x--; y--;
      hq.push_back(point(x, y));
    }
    sort(hq.begin(), hq.end());
    memset(board, -1, sizeof board);
    bfs();
    int q; cin >> q;
    while (q--) {
      int x, y; cin >> x >> y; x--; y--;
      int ans = board[x][y];
      cout << hq[ans].i + 1 << " " << hq[ans].j + 1 << endl;
    }
  }
  return 0;
}