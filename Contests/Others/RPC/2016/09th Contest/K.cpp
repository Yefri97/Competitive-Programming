/*
 *  RPC 9-th Contest 2016
 *  Problem K: Polygon Restoration
 *  Status: Accepted \ Sweep Line + Geometry
 */

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MAX_N = 50;

struct point {
  int x, y, id;
  point(int _x, int _y, int _id) : x(_x), y(_y), id(_id) {}

  bool operator < (point other) const {
    if (x != other.x)
      return x < other.x;
    return y < other.y;
  }

};

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n, cs = 0;
  while (cin >> n && n) {
    cout << "Polygon #" << ++cs << ": ";
    vector<point> vp_ver, vp_hor;
    for (int i = 0; i < n; i++) {
      int x, y; cin >> x >> y;
      vp_ver.push_back(point(x, y, i));
      vp_hor.push_back(point(y, x, i));
    }

    int graph[MAX_N][5];
    
    sort(vp_ver.begin(), vp_ver.end());
    for (int i = 0; i < vp_ver.size(); i += 2) {
      point pa = vp_ver[i], pb = vp_ver[i + 1];
      graph[pa.id][0] = pb.id;
      graph[pb.id][0] = pa.id;
    }

    sort(vp_hor.begin(), vp_hor.end());
    for (int i = 0; i < vp_hor.size(); i += 2) {
      point pa = vp_hor[i], pb = vp_hor[i + 1];
      graph[pa.id][1] = pb.id;
      graph[pb.id][1] = pa.id;
    }

    int id = vp_hor[0].id, k = 0;
    while (n--) {
      cout << id + 1;
      k = 1 - k;
      id = graph[id][k];
      if (n) cout << " ";
    }
    cout << endl;
  }
  return 0;
}