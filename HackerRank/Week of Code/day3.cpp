#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

struct piece { 
  char id, color;
  int posi, posj;
  piece() : id('.'), color('#'), posi(-1), posj(-1) {}
  piece(char _id, char _color, int _posi, int _posj) : id(_id), color(_color), posi(_posi), posj(_posj) {}
  bool operator == (piece other) const {
    return id == other.id && color == other.color;
  }
} QW, QB, board[5][5];

void show() {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) 
      cout << board[i][j].id << board[i][j].color << " ";
    cout << endl;
  }
}

vector<ii> movPiece(piece pc) {
  vector<ii> ans;
  int ui = pc.posi, uj = pc.posj;
  if (pc.id == 'Q') {
    for (int i = ui - 1, j = uj - 1; i > 0 && j > 0; i--, j--) {
      if (board[ui][uj].color == board[i][j].color) break;
      ans.push_back(ii(i, j));
      if (board[ui][uj].color == 'W' && board[i][j].color == 'B' ||
          board[ui][uj].color == 'B' && board[i][j].color == 'W') break;
    }
    for (int i = ui - 1, j = uj; i > 0; i--) {
      if (board[ui][uj].color == board[i][j].color) break;
      ans.push_back(ii(i, j));
      if (board[ui][uj].color == 'W' && board[i][j].color == 'B' ||
          board[ui][uj].color == 'B' && board[i][j].color == 'W') break;
    }
    for (int i = ui - 1, j = uj + 1; i > 0 && j < 4; i--, j++) {
      if (board[ui][uj].color == board[i][j].color) break;
      ans.push_back(ii(i, j));
      if (board[ui][uj].color == 'W' && board[i][j].color == 'B' ||
          board[ui][uj].color == 'B' && board[i][j].color == 'W') break;
    }
    for (int i = ui, j = uj + 1; j < 4; j++) {
      if (board[ui][uj].color == board[i][j].color) break;
      ans.push_back(ii(i, j));
      if (board[ui][uj].color == 'W' && board[i][j].color == 'B' ||
          board[ui][uj].color == 'B' && board[i][j].color == 'W') break;
    }
    for (int i = ui + 1, j = uj + 1; i < 4 && j < 4; i++, j++) {
      if (board[ui][uj].color == board[i][j].color) break;
      ans.push_back(ii(i, j));
      if (board[ui][uj].color == 'W' && board[i][j].color == 'B' ||
          board[ui][uj].color == 'B' && board[i][j].color == 'W') break;
    }
    for (int i = ui + 1, j = uj; i < 4; i++) {
      if (board[ui][uj].color == board[i][j].color) break;
      ans.push_back(ii(i, j));
      if (board[ui][uj].color == 'W' && board[i][j].color == 'B' ||
          board[ui][uj].color == 'B' && board[i][j].color == 'W') break;
    }
    for (int i = ui + 1, j = uj - 1; i < 4 && j > 0; i++, j--) {
      if (board[ui][uj].color == board[i][j].color) break;
      ans.push_back(ii(i, j));
      if (board[ui][uj].color == 'W' && board[i][j].color == 'B' ||
          board[ui][uj].color == 'B' && board[i][j].color == 'W') break;
    }
    for (int i = ui, j = uj - 1; j > 0; j--) {
      if (board[ui][uj].color == board[i][j].color) break;
      ans.push_back(ii(i, j));
      if (board[ui][uj].color == 'W' && board[i][j].color == 'B' ||
          board[ui][uj].color == 'B' && board[i][j].color == 'W') break;
    }
  }
  if (pc.id == 'N') {
    int mi[10] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int mj[10] = {1, 2, 2, 1, -1, -2, -2, -1};
    for (int i = 0; i < 8; i++) {
      int vi = ui + mi[i], vj = uj + mj[i];
      if (vi < 0 || vi >= 4 || vj < 0 || vj >= 4) continue;
      ans.push_back(ii(vi, vj));
    }
  }
  if (pc.id == 'B') {
    for (int i = ui - 1, j = uj - 1; i > 0 && j > 0; i--, j--) {
      if (board[ui][uj].color == board[i][j].color) break;
      ans.push_back(ii(i, j));
      if (board[ui][uj].color == 'W' && board[ui][uj].color == 'B' ||
          board[ui][uj].color == 'B' && board[ui][uj].color == 'W') break;
    }
    for (int i = ui - 1, j = uj + 1; i > 0 && j < 4; i--, j++) {
      if (board[ui][uj].color == board[i][j].color) break;
      ans.push_back(ii(i, j));
      if (board[ui][uj].color == 'W' && board[ui][uj].color == 'B' ||
          board[ui][uj].color == 'B' && board[ui][uj].color == 'W') break;
    }
    for (int i = ui + 1, j = uj + 1; i < 4 && j < 4; i++, j++) {
      if (board[ui][uj].color == board[i][j].color) break;
      ans.push_back(ii(i, j));
      if (board[ui][uj].color == 'W' && board[ui][uj].color == 'B' ||
          board[ui][uj].color == 'B' && board[ui][uj].color == 'W') break;
    }
    for (int i = ui + 1, j = uj - 1; i < 4 && j > 0; i++, j--) {
      if (board[ui][uj].color == board[i][j].color) break;
      ans.push_back(ii(i, j));
      if (board[ui][uj].color == 'W' && board[ui][uj].color == 'B' ||
          board[ui][uj].color == 'B' && board[ui][uj].color == 'W') break;
    }
  }
  if (pc.id == 'R') {
    for (int i = ui - 1, j = uj; i > 0; i--) {
      if (board[ui][uj].color == board[i][j].color) break;
      ans.push_back(ii(i, j));
      if (board[ui][uj].color == 'W' && board[ui][uj].color == 'B' ||
          board[ui][uj].color == 'B' && board[ui][uj].color == 'W') break;
    }
    for (int i = ui, j = uj + 1; j < 4; j++) {
      if (board[ui][uj].color == board[i][j].color) break;
      ans.push_back(ii(i, j));
      if (board[ui][uj].color == 'W' && board[ui][uj].color == 'B' ||
          board[ui][uj].color == 'B' && board[ui][uj].color == 'W') break;
    }
    for (int i = ui + 1, j = uj; i < 4; i++) {
      if (board[ui][uj].color == board[i][j].color) break;
      ans.push_back(ii(i, j));
      if (board[ui][uj].color == 'W' && board[ui][uj].color == 'B' ||
          board[ui][uj].color == 'B' && board[ui][uj].color == 'W') break;
    }
    for (int i = ui, j = uj - 1; j > 0; j--) {
      if (board[ui][uj].color == board[i][j].color) break;
      ans.push_back(ii(i, j));
      if (board[ui][uj].color == 'W' && board[ui][uj].color == 'B' ||
          board[ui][uj].color == 'B' && board[ui][uj].color == 'W') break;
    }
  }
  return ans;
}

bool solver(int m, char color) {
  //cout << m << " " << color << endl;
  //show();
  if (m == 0) return false;
  bool ans = false;
  for (int ui = 0; ui < 4; ui++) for (int uj = 0; uj < 4; uj++) {
    piece pc = board[ui][uj];
    if (pc.id == '.' || pc.color != color) continue;
    //cout << pc.id << " " << pc.color << endl;
    vector<ii> mov = movPiece(pc);
    //cout << pc.id << pc.color << " " << mov.size() << endl;
    //for (int i = 0; i < mov.size(); i++) cout << mov[i].first << "|" << mov[i].second << " "; cout << endl;
    for (int i = 0; i < mov.size(); i++) {
      int vi = mov[i].first, vj = mov[i].second;
      //cout << vi << " " << vj << endl; cout << endl;
      if (board[vi][vj].id == 'Q' && board[vi][vj].color == 'W') return false;
      if (board[vi][vj].id == 'Q' && board[vi][vj].color == 'B') return true;
      piece temp = board[vi][vj];
      board[vi][vj] = piece(pc.id, pc.color, vi, vj);
      board[ui][uj] = piece();
      ans |= solver(m - 1, (color == 'W')? 'B' : 'W');
      if (ans) return true;
      board[vi][vj] = temp;
      board[ui][uj] = pc;
    }
  }
  return ans;
}

int main() {
  int t; cin >> t;
  while (t--) {
    int w, b, m; cin >> w >> b >> m;

    for (int i = 0; i < w; i++) {
      char p, col, row; cin >> p >> col >> row;
      int r = row - '0' - 1, c = col - 'A';
      piece pc = piece(p, 'W', r, c);
      if (p == 'Q') QW = pc;
      board[r][c] = pc;
    }
    for (int i = 0; i < b; i++) {
      char p, col, row; cin >> p >> col >> row;
      int r = row - '0' - 1, c = col - 'A';
      piece pc = piece(p, 'B', r, c);
      if (p == 'Q') QB = pc;
      board[r][c] = pc;
    }

    //show();

    bool ans = solver(m, 'W');

    cout << ((ans)? "YES" : "NO") << endl;

  }
  return 0;
}