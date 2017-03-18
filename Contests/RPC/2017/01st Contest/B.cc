/*
 *  RPC 01st Contest 2017
 *  Problem B: Checkers
 *  Status: Accepted
 */

#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cout << #x << ": " << x << endl
#define endl '\n'

typedef vector<vector<char> > mat;

int mx[] = {1, -1, -1, 1};
int my[] = {1, 1, -1, -1};
int n;

struct st{
  int x, y, w;
  st(){}
  st(int _x, int _y, int _w): x(_x), y(_y), w(_w){}
};

bool check(int x, int y, int x1, int y1, mat &b) {
  if (x < 0 || x >= n || y < 0 || y >= n) return false;
  if (b[x][y] != 'W') return false;
  if (x1 < 0 || x1 >= n || y1 < 0 || y1 >= n) return false;
  if (b[x1][y1] != '_') return false;
  return true;
}

bool won;
bool vi[30][30][200];

void backtrack(int x, int y, int w, mat &b) {
  if (won) return; 
  vi[x][y][w] = true;
  
  for (int i = 0; i < 4; i++) {
    int tx = x + mx[i];
    int ty = y + my[i];
    int tx2 = x + mx[i] * 2;
    int ty2 = y + my[i] * 2;
    if (check(tx, ty, tx2, ty2, b)) {
      if (vi[tx2][ty2][w - 1]) return;
      b[x][y] = '_';
      b[tx][ty] = '_';
      b[tx2][ty2] = 'B';
      if (w - 1 == 0) {
        won = true;
        return;
      }
      backtrack(tx2, ty2, w - 1, b);
      b[x][y] = 'B';
      b[tx][ty] = 'W';
      b[tx2][ty2] = '_';
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  while (cin >> n) {
    mat board(n, vector<char>(n)), test;
    int w = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> board[i][j];
        w += (board[i][j] == 'W');
      }
    }
    int sol = 0;
    string ans = " ";
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (board[i][j] == 'B') {
          memset(vi, 0, sizeof vi);
          won = false;
          test = board;
          backtrack(i, j, w, test);
          if (won) {
            sol++;
            ans = 'a' + j;
            stringstream ss; ss << n - i;
            string tmp; ss >> tmp;
            ans += tmp;
          }
        }
      }
    }
    if (sol == 0) cout << "None" << endl;
    else if (sol != 1) cout << "Multiple" << endl;
    else cout << ans << endl;
  }
}

