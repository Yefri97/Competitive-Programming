#include <bits/stdc++.h>
using namespace std;

int main() {
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> game(n);
    for (int i = 0; i < n; i++)
      cin >> game[i];
    game.push_back(1); game.push_back(1);
    bool ans = false;
    int it = 0;
    while (it < game.size() and game[it]) it++;
    while (it < game.size()) {
      if (game[it + 2] == 0 or (game[it + 1] == 0 and game[it + 3] == 0))
        while (!(game[it] and game[it + 1])) ans ^= true, it++;
      else
        it++;
      while (it < game.size() and game[it]) it++;
    }
    cout << (ans ? "Alice" : "Bob") << endl;
  }
  return 0;
}