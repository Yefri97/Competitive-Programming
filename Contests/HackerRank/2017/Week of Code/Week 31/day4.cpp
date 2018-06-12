#include <bits/stdc++.h>
#define endl '\n'
#define EPS 1e-9
using namespace std;

typedef pair<int, int> ii;

struct Edge {
  double w;
  int a, b, u, v;
  Edge() {}
  Edge(double _w, int _a, int _b, int _u, int _v) : w(_w), a(_a), b(_b), u(_u), v(_v) {}
  bool operator < (const Edge &o) const { return w < o.w; }
};

struct UnionFind {
  vector<int> p, rank, setSize;
  int numSets;
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

int n, m, A, B;
vector<Edge> g;

int check(double C) {
  for (int i = 0; i < m; i++)
    g[i].w = g[i].a - C * g[i].b;
  sort(g.rbegin(), g.rend());

  A = 0, B = 0;
  UnionFind UF(n);
  for (int i = 0; i < m; i++) {
    Edge front = g[i];
    if (!UF.isSameSet(front.u, front.v)) {
      A += front.a; B += front.b;
      UF.unionSet(front.u, front.v);
    }
  }
  return A >= C * B;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v, a, b; cin >> u >> v >> a >> b;
    g.push_back(Edge(-1.0, a, b, u, v));
  }
  double lo = 0, hi = 1e9;
  for (int i = 0; i < 100; i++) {
    double mid = (hi + lo) / 2;
    if (check(mid))
      lo = mid;
    else
      hi = mid;
  }
  int gcd = __gcd(A, B);
  cout << A / gcd << "/" << B / gcd << endl;
  return 0;
}