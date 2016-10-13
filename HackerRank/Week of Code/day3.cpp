#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

struct piece { 
  char id, color;
  piece() : id('.'), color('#') {}
  piece(char _id, char _color) : id(_id), color(_color) {}
} board[5][5];

vector<ii> movPiece(int ui, int uj) {
  vector<ii> ans;
  piece pc = board[ui][uj];
  if (pc.id == 'Q') {
    for (int mi = ui - 1, mj = uj - 1; mi >= 0 && mj >= 0; mi--, mj--) {
      if (board[ui][uj].color == board[mi][mj].color) break;
      ans.push_back(ii(mi, mj));
      if (board[mi][mj].color != '#' && board[ui][uj].color != board[mi][mj].color) break;
    }
    for (int mi = ui - 1, mj = uj; mi >= 0; mi--) {
      if (board[ui][uj].color == board[mi][mj].color) break;
      ans.push_back(ii(mi, mj));
      if (board[mi][mj].color != '#' && board[ui][uj].color != board[mi][mj].color) break;
    }
    for (int mi = ui - 1, mj = uj + 1; mi >= 0 && mj < 4; mi--, mj++) {
      if (board[ui][uj].color == board[mi][mj].color) break;
      ans.push_back(ii(mi, mj));
      if (board[mi][mj].color != '#' && board[ui][uj].color != board[mi][mj].color) break;
    }
    for (int mi = ui, mj = uj + 1; mj < 4; mj++) {
      if (board[ui][uj].color == board[mi][mj].color) break;
      ans.push_back(ii(mi, mj));
      if (board[mi][mj].color != '#' && board[ui][uj].color != board[mi][mj].color) break;
    }
    for (int mi = ui + 1, mj = uj + 1; mi < 4 && mj < 4; mi++, mj++) {
      if (board[ui][uj].color == board[mi][mj].color) break;
      ans.push_back(ii(mi, mj));
      if (board[mi][mj].color != '#' && board[ui][uj].color != board[mi][mj].color) break;
    }
    for (int mi = ui + 1, mj = uj; mi < 4; mi++) {
      if (board[ui][uj].color == board[mi][mj].color) break;
      ans.push_back(ii(mi, mj));
      if (board[mi][mj].color != '#' && board[ui][uj].color != board[mi][mj].color) break;
    }
    for (int mi = ui + 1, mj = uj - 1; mi < 4 && mj >= 0; mi++, mj--) {
      if (board[ui][uj].color == board[mi][mj].color) break;
      ans.push_back(ii(mi, mj));
      if (board[mi][mj].color != '#' && board[ui][uj].color != board[mi][mj].color) break;
    }
    for (int mi = ui, mj = uj - 1; mj >= 0; mj--) {
      if (board[ui][uj].color == board[mi][mj].color) break;
      ans.push_back(ii(mi, mj));
      if (board[mi][mj].color != '#' && board[ui][uj].color != board[mi][mj].color) break;
    }
  }
  if (pc.id == 'N') {
    int vi[10] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int vj[10] = {1, 2, 2, 1, -1, -2, -2, -1};
    for (int i = 0; i < 8; i++) {
      int mi = ui + vi[i], mj = uj + vj[i];
      if (mi < 0 || mi >= 4 || mj < 0 || mj >= 4) continue;
      if (board[ui][uj].color == board[mi][mj].color) continue;
      ans.push_back(ii(mi, mj));
    }
  }
  if (pc.id == 'B') {
    for (int mi = ui - 1, mj = uj - 1; mi >= 0 && mj >= 0; mi--, mj--) {
      if (board[ui][uj].color == board[mi][mj].color) break;
      ans.push_back(ii(mi, mj));
      if (board[mi][mj].color != '#' && board[ui][uj].color != board[mi][mj].color) break;
    }
    for (int mi = ui - 1, mj = uj + 1; mi >= 0 && mj < 4; mi--, mj++) {
      if (board[ui][uj].color == board[mi][mj].color) break;
      ans.push_back(ii(mi, mj));
      if (board[mi][mj].color != '#' && board[ui][uj].color != board[mi][mj].color) break;
    }
    for (int mi = ui + 1, mj = uj + 1; mi < 4 && mj < 4; mi++, mj++) {
      if (board[ui][uj].color == board[mi][mj].color) break;
      ans.push_back(ii(mi, mj));
      if (board[mi][mj].color != '#' && board[ui][uj].color != board[mi][mj].color) break;
    }
    for (int mi = ui + 1, mj = uj - 1; mi < 4 && mj >= 0; mi++, mj--) {
      if (board[ui][uj].color == board[mi][mj].color) break;
      ans.push_back(ii(mi, mj));
      if (board[mi][mj].color != '#' && board[ui][uj].color != board[mi][mj].color) break;
    }
  }
  if (pc.id == 'R') {
    for (int mi = ui - 1, mj = uj; mi >= 0; mi--) {
      if (board[ui][uj].color == board[mi][mj].color) break;
      ans.push_back(ii(mi, mj));
      if (board[mi][mj].color != '#' && board[ui][uj].color != board[mi][mj].color) break;
    }
    for (int mi = ui, mj = uj + 1; mj < 4; mj++) {
      if (board[ui][uj].color == board[mi][mj].color) break;
      ans.push_back(ii(mi, mj));
      if (board[mi][mj].color != '#' && board[ui][uj].color != board[mi][mj].color) break;
    }
    for (int mi = ui + 1, mj = uj; mi < 4; mi++) {
      if (board[ui][uj].color == board[mi][mj].color) break;
      ans.push_back(ii(mi, mj));
      if (board[mi][mj].color != '#' && board[ui][uj].color != board[mi][mj].color) break;
    }
    for (int mi = ui, mj = uj - 1; mj >= 0; mj--) {
      if (board[ui][uj].color == board[mi][mj].color) break;
      ans.push_back(ii(mi, mj));
      if (board[mi][mj].color != '#' && board[ui][uj].color != board[mi][mj].color) break;
    }
  }
  return ans;
}

bool solver(int m, char color) {
  if (m == 0) return color == 'B';
  bool ans = false;
  for (int ui = 0; ui < 4; ui++) for (int uj = 0; uj < 4; uj++) {
    piece pc = board[ui][uj];
    if (pc.id == '.' || pc.color != color) continue;
    vector<ii> mov = movPiece(ui, uj);
    for (int i = 0; i < mov.size(); i++) {
      int mi = mov[i].first, mj = mov[i].second;
      piece temp = board[mi][mj];
      if (temp.id == 'Q') return true;
      board[mi][mj] = pc;
      board[ui][uj] = piece();
      if (!solver(m - 1, (color == 'W')? 'B' : 'W')) ans = true;
      board[mi][mj] = temp;
      board[ui][uj] = pc;
    }
  }
  return ans;
}

int main() {
  int t; cin >> t;
  while (t--) {
    for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) board[i][j] = piece();
    int w, b, m; cin >> w >> b >> m;

    for (int i = 0; i < w; i++) {
      char p, col, row; cin >> p >> col >> row;
      int r = row - '0' - 1, c = col - 'A';
      piece pc = piece(p, 'W');
      board[r][c] = pc;
    }
    for (int i = 0; i < b; i++) {
      char p, col, row; cin >> p >> col >> row;
      int r = row - '0' - 1, c = col - 'A';
      piece pc = piece(p, 'B');
      board[r][c] = pc;
    }
    
    bool ans = solver(m, 'W');

    cout << ((ans)? "YES" : "NO") << endl;

  }
  return 0;
}