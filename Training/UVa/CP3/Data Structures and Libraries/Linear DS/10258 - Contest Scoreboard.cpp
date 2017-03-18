// C++ STL algorithm
#include <bits/stdc++.h>
using namespace std;

struct part {
  int id, num_problems, penalty, actived;
  part(int i, int np, int pty, int act) { id = i; num_problems = np; penalty = pty; actived = act; }
  bool operator < (part other) const {
    if (actived != other.actived)
      return actived > other.actived;
    else
      if (num_problems != other.num_problems) 
        return num_problems > other.num_problems;
      else
        if (penalty != other.penalty)
          return penalty < other.penalty;
        else
          return id < other.id;
  }
};

int to_num(string s) { return atoi(s.c_str()); }

vector<string> split(string line) {
  istringstream iss(line);
  vector<string> ans;
  while (iss >> line) ans.push_back(line);
  return ans;
}

int main() {
  bool first = true;
  int t; cin >> t; cin.ignore(); t++;
  while (t--) {
    vector<part> vp;
    for (int i = 0; i < 100; i++)
      vp.push_back(part(i, 0, 0, 0));
    int board[110][20];
    memset(board, 0, sizeof board);
    string line; 
    while(getline(cin, line) && line.size()) {
      vector<string> vs = split(line);
      int a = to_num(vs[0]), b = to_num(vs[1]), c = to_num(vs[2]); a--; b--;
      char ch = vs[3][0];
      vp[a].actived = 1;
      if (board[a][b] == -1) continue;
      if (ch == 'I')
        board[a][b]++;
      if (ch == 'C') {
        vp[a].penalty += 20 * board[a][b] + c;
        vp[a].num_problems++;
        board[a][b] = -1;
      }
    }
    sort(vp.begin(), vp.end());
    for (int i = 0; i < vp.size(); i++) {
      part p = vp[i];
      if (!p.actived) break;
      cout << p.id + 1 << " " << p.num_problems << " " << p.penalty << endl;
    }
    if (!first && t) cout << endl; first = false;
  }
  return 0;
}