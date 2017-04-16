#include <bits/stdc++.h>
using namespace std;

int main() {
  string line; cin >> line;
  int n = line.size();
  line.push_back('z');
  string minc = line;
  for (int i = n - 2; i >= 0; i--)
    minc[i] = min(line[i], minc[i + 1]);
  stack<char> s;
  string ans;
  for (int i = 0; i < n; i++) {
    char key = minc[i];
    while (key != line[i]) {
      s.push(line[i]);
      i++;
    }
    s.push(line[i]);
    while (!s.empty() and s.top() <= minc[i + 1]) {
      ans.push_back(s.top()); s.pop();
    }
  }
  cout << ans << endl;
  return 0;
}