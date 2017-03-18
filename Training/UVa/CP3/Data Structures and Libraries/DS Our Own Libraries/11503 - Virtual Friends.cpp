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

const int MAXN = 100000;

int idx;
map<string, int> id;

int getId(string name) {
  if (id.find(name) == id.end()) id[name] = idx++;
  return id[name];
}

int main() {
  int t; cin >> t;
  while (t--) {
    idx = 0;
    id.clear();
    UnionFind friends(MAXN);
    int m; cin >> m;
    while (m--) {
      string a, b; cin >> a >> b;
      int u = getId(a), v = getId(b);
      friends.unionSet(u, v);
      cout << friends.sizeOfSet(u) << endl;
    }
  }
  return 0;
}