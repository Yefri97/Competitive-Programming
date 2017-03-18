// Union-Find Disjoint Set
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

class UnionFind {
private:
  vi p, rank, setSize;
  int numSets;
public:
  UnionFind(int N) {
    setSize.assign(N, 1); numSets = N; rank.assign(N, 0);
    p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i;
  }
  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  void unionSet(int i, int j) { 
    if (!isSameSet(i, j)) { 
      numSets--; 
      int x = findSet(i), y = findSet(j);
      if (rank[x] > rank[y]) { 
        p[y] = x; setSize[x] += setSize[y]; 
      } else { 
        p[x] = y; setSize[y] += setSize[x];
        if (rank[x] == rank[y]) rank[y]++; 
      } 
    } 
  }
  int numDisjointSets() { return numSets; }
  int sizeOfSet(int i) { return setSize[findSet(i)]; }
};

int main() {
  int t; cin >> t;
  string s; cin >> s;
  while (t--) {
    int n = atoi(s.c_str()), ans[5]; ans[0] = ans[1] = 0;
    UnionFind ds(n);
    while (cin >> s && (s == "c" || s == "q")) {
      int a, b; cin >> a >> b; a--; b--;
      if (s == "c")
        ds.unionSet(a, b);
      else
        ans[ds.isSameSet(a, b)]++;
    }
    cout << ans[1] << "," << ans[0] << endl;
    if (t) cout << endl;
  }
  return 0;
}