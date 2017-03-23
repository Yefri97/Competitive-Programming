#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

ii source, target;
vector<bool> used;
vector<ii> pieces;

bool solver(int curr, int k) {
  if (k == 0) return curr == target.first;
  for (int i = 0; i < pieces.size(); i++) {
    if (used[i]) continue;
    if (curr == pieces[i].first) {
      used[i] = true;
      if(solver(pieces[i].second, k - 1)) return true;
      used[i] = false;
    }
    if (curr == pieces[i].second) {
      used[i] = true;
      if (solver(pieces[i].first, k - 1)) return true;
      used[i] = false;
    }
  }
  return false;
}

int main() {
  int m;
  while (cin >> m and m) {
    int n; cin >> n;
    cin >> source.first >> source.second;
    cin >> target.first >> target.second;
    pieces.assign(n, ii(0, 0));
    used.assign(n, false);
    for (int i = 0; i < n; i++)
      cin >> pieces[i].first >> pieces[i].second;
    bool ans = solver(source.second, m);
    cout << ((ans)? "YES" : "NO") << endl;
  }
  return 0;
}
