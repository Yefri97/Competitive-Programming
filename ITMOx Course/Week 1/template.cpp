#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

const int INF = 1e9;

int main() {
  ifstream cin("template.in");
  ofstream cout("template.out");
  int m, n; cin >> m >> n; cin.ignore();
  vector<ii> arr(200);
  string line;
  for (int i = 0; i < n; i++) {
    getline(cin, line);
    for (int j = 0; j < m; j++) {
      int c = line[j];
      arr[c] = ii(i, j);
    }
  }
  getline(cin, line);
  string name_ans;
  int ans = INF;
  for (int i = 0; i < 3; i++) {
    string name; getline(cin, name);
    int acc = 0;
    while (getline(cin, line) && line.size()) {
      for (int j = 0; j < line.size() - 1; j++) {
        int curr = line[j], next = line[j + 1];
        acc += max(abs(arr[curr].first - arr[next].first), abs(arr[curr].second - arr[next].second));
      }
    }
    if (acc < ans) {
      name_ans = name;
      ans = acc;
    }
  }
  cout << name_ans << endl;
  cout << ans << endl;
  return 0;
}