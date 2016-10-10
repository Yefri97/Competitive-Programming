#include <bits/stdc++.h>
using namespace std;

int n, m;
int mi[10] = {-1, -1, -1, 0, 1, 1, 1, 0};
int mj[10] = {-1, 0, 1, 1, 1, 0, -1, -1};

const int MAX_N = 100;
char board[MAX_N + 10][MAX_N + 10];

int flood_fill(int r, int c, char color) {
  if (r < 0 || r >= n || c < 0 || c >= m) return 0;
  if (board[r][c] != color) return 0;
  int ans = 1;
  board[r][c] = (color == 'W')? '#' : 'W';
  for (int i = 0; i < 8; i++) {
    ans += flood_fill(r + mi[i], c + mj[i], color);
  }
  return ans;
}

int to_int(string s) {
  return atoi(s.c_str());
}

int next_int() {
  string line; getline(cin, line);
  return to_int(line);
}

int main() {
  int t = next_int();
  string temp; getline(cin, temp);
  while (t--) {
    n = 0;
    string line;
    for (int i = 0; getline(cin, line) && (line[0] == 'W' || line[0] == 'L'); i++, n++)
      for (int j = 0; j < line.size(); j++, m = line.size())
        board[i][j] = line[j];
    while (true) {
      istringstream iss(line);
      iss >> line;
      int a = to_int(line); a--;
      iss >> line;
      int b = to_int(line); b--;
      int ans = flood_fill(a, b, board[a][b]);
      //for (int i = 0; i < n; i++) { for (int j = 0; j < m; j++) cout << board[i][j] << " "; cout << endl; }
      cout << ans << endl;
      getline(cin, line);
      if (!line.size()) break;
    }
    if (t) cout << endl;
  }
  return 0;
}