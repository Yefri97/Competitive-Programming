// Graph Data Structures
#include <bits/stdc++.h>
using namespace std;

int main() {
  int t; cin >> t;
  while (t--) {
    int v = 0, e = 0, acorns = 0;
    bitset<26> bs; bs.set();
    string edge;
    while (cin >> edge and edge[0] != '*') {
      int a = edge[1] - 'A', b = edge[3] - 'A';
      bs.reset(a);
      bs.reset(b);
      e++;
    }
    string nodes; cin >> nodes;
    for (int i = 0; i < nodes.size(); i += 2) {
      int n = nodes[i] - 'A';
      if (bs.test(n)) acorns++;
      v++;
    }
    cout << "There are " << v - e - acorns << " tree(s) and " << acorns << " acorn(s)." << endl;
  }
	return 0;
}