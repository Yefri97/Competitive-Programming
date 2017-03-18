// Union-Find Disjoint Set
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 26;

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
  int n;
  while (cin >> n) {
    int m; cin >> m;
    string init; cin >> init;
    int a = init[0] - 'A', b = init[1] - 'A', c = init[2] - 'A';
    UnionFind wakeUp(MAXN);
    wakeUp.unionSet(b, a);
    wakeUp.unionSet(c, a);
    vector<vi> g(MAXN);
    set<int> nodes;
    while (m--) {
      string edge; cin >> edge;
      int u = edge[0] - 'A', v = edge[1] - 'A';
      nodes.insert(u);
      nodes.insert(v);
      g[u].push_back(v);
      g[v].push_back(u);
    }
    bool done = false;
    int ans = 0;
    while (!done) {
      vector<int> cont(MAXN);
      for (set<int>::iterator it = nodes.begin(); it != nodes.end(); it++) {
        int u = *it;
        if (wakeUp.isSameSet(u, a)) {
          for (int i = 0; i < g[u].size(); i++) {
            int v = g[u][i];
            if (!wakeUp.isSameSet(v, a)) cont[v]++;
          }
        }
      }
      done = true;
      for (int i = 0; i < cont.size(); i++) {
        if (cont[i] >= 3) {
          wakeUp.unionSet(i, a);
          done = false;
        }
      }
      ans++;
    }
    if (wakeUp.sizeOfSet(a) == n) {
      
      cout << "WAKE UP IN, " << ans - 1 << ", YEARS" << endl;
    } else {
      cout << "THIS BRAIN NEVER WAKES UP" << endl;
    }
  }
  return 0;
}