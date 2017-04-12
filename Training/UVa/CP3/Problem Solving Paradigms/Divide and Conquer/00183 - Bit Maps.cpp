// Divide and Conquer Problems
#include <bits/stdc++.h>
using namespace std;

vector< vector<char> > mat;

string decomposition(int top, int bottom, int left, int right) {
  char key = mat[top][left];
  bool flag = true;
  for (int i = top; i <= bottom; i++)
    for (int j = left; j <= right; j++)
      if (mat[i][j] != key) flag = false;
  if (flag) return key - '0' ? "1" : "0";
  string target = "D";
  int midV = (top + bottom) / 2, midH = (left + right) / 2;
  if (top == bottom) {
    target += decomposition(top, bottom, left, midH);
    target += decomposition(top, bottom, midH + 1, right);
  } else if (left == right) {
    target += decomposition(top, midV, left, right);
    target += decomposition(midV + 1, bottom, left, right);
  } else {
    target += decomposition(top, midV, left, midH);
    target += decomposition(top, midV, midH + 1, right);
    target += decomposition(midV + 1, bottom, left, midH);
    target += decomposition(midV + 1, bottom, midH + 1, right);
  }
  return target;
}

void composition(int top, int bottom, int left, int right) {
  char c; cin >> c;
  if (c == 'D') {
    int midV = (top + bottom) / 2, midH = (left + right) / 2;
    if (top == bottom) {
      composition(top, bottom, left, midH);
      composition(top, bottom, midH + 1, right);
    } else if (left == right) {
      composition(top, midV, left, right);
      composition(midV + 1, bottom, left, right);
    } else {
      composition(top, midV, left, midH);
      composition(top, midV, midH + 1, right);
      composition(midV + 1, bottom, left, midH);
      composition(midV + 1, bottom, midH + 1, right);
    }
  } else {
    for (int i = top; i <= bottom; i++)
      for (int j = left; j <= right; j++)
        mat[i][j] = c;
  }
}

int main() {
  char c;
  while (cin >> c and c != '#') {
    int n, m; cin >> n >> m;
    string ans;
    mat.assign(n, vector<char>(m));
    if (c == 'B') {
      for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
          cin >> mat[i][j];
      ans = decomposition(0, n - 1, 0, m - 1);
    } else {
      composition(0, n - 1, 0, m - 1);
      for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
          ans.push_back(mat[i][j]);
        }
    }
    cout << (c == 'B' ? "D" : "B") << setw(4) << n << setw(4) << m << endl;;
    for (int i = 0; i < ans.size(); i++) {
      if (i != 0 and i % 50 == 0) cout << endl;
      cout << ans[i];
    }
    cout << endl;
  }
  return 0;
}