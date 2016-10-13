#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

struct piece { 
  char id, color;
  piece() : id('.'), color('#') {}
  piece(char _id, char _color) : id(_id), color(_color) {}
} board[5][5];

void show() {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) 
      cout << board[i][j].id << board[i][j].color << " ";
    cout << endl;
  }
  cout << endl;
}

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
  //if (m == 1) {
  //  cout << m << " " << color << endl;
  //  show();
  //}
  if (m == 0) return false;
  bool ans = ((color == 'W')? true : false);
  for (int ui = 0; ui < 4; ui++) for (int uj = 0; uj < 4; uj++) {
    piece pc = board[ui][uj];
    if (pc.id == '.' || pc.color != color) continue;
    //cout << pc.id << " " << pc.color << endl;
    vector<ii> mov = movPiece(ui, uj);
    //cout << pc.id << pc.color << " " << mov.size() << endl;
    //for (int i = 0; i < mov.size(); i++) cout << mov[i].first << "|" << mov[i].second << " "; cout << endl;
    for (int i = 0; i < mov.size(); i++) {
      int mi = mov[i].first, mj = mov[i].second;
      piece temp = board[mi][mj];
      //cout << mi << " " << mj << endl; cout << endl;
      if (temp.id == 'Q' && temp.color == 'W') return false;
      if (temp.id == 'Q' && temp.color == 'B') return true;
      board[mi][mj] = pc;
      board[ui][uj] = piece();
      //if (pc.id == 'B') { cout << m << " " << color << endl; show(); }
      int b = solver(m - 1, (color == 'W')? 'B' : 'W');
      if (color == 'B') ans |= b;
      if (color == 'W') ans &= b; 
      //if (solver(m - 1, (color == 'W')? 'B' : 'W')) return true;
      board[mi][mj] = temp;
      board[ui][uj] = pc;
      //if (ans) { show(); return true; }
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
    //show();
    bool ans = solver(m, 'W');
    //show();

    cout << ((ans)? "YES" : "NO") << endl;

  }
  return 0;
}