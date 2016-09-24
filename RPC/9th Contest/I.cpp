/*
 *  RPC 9-th Contest 2016
 *  Problem I: Walking in the Sun
 *  Status: Accepted \ Dijkstra + Geometry
 */

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

typedef vector<double> vi;
typedef pair<double, int> ii;

struct circle {
  double x, y, r;
};

double distCircle(circle a, circle b) {
  double dx = a.x - b.x;
  double dy = a.y - b.y;
  return max(0.0, sqrt(dx * dx + dy * dy) - (a.r + b.r));
}

const int MAX_N = 50;
int V;
const double INF = 1000000.0;
double g[MAX_N + 10][MAX_N + 10];

double dijkstra(int in, int out) {
  vi dist(V, INF); dist[in] = 0.0;
  priority_queue< ii, vector<ii>, greater<ii> > pq; pq.push(ii(0.0, in));
  while (!pq.empty()) {
    ii front = pq.top(); pq.pop();
    double d = front.first;
    int u = front.second;
    if (d > dist[u]) continue;
    for (int i = 0; i < V; i++) {
      double v = g[u][i];
      if (dist[u] + v < dist[i]) {
        dist[i] = dist[u] + v;
        pq.push(ii(dist[i], i));
      }
    }
  }
  return dist[out];
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int t, cs = 0; cin >> t;
  while (t--) {
    cout << "Campus #" << ++cs << ":" << endl;
    int n; cin >> n;

    V = n + 2;
    for (int i = 0; i < V; i++)
      g[i][i] = 0;

    circle shadow[MAX_N + 10];
    for (int i = 0; i < n; i++)
      cin >> shadow[i].x >> shadow[i].y >> shadow[i].r;

    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        double d = distCircle(shadow[i], shadow[j]);
        g[i + 2][j + 2] = d;
        g[j + 2][i + 2] = d;
      }
    }

    int q, csq = 0; cin >> q;
    while (q--) {
      cout << "Path #" << ++csq << ": ";
      circle in, out;
      cin >> in.x >> in.y >> out.x >> out.y;

      in.r = out.r = 0.0;
      g[0][1] = g[1][0] = distCircle(in, out);

      for (int i = 0; i < n; i++) {
        double d = distCircle(in, shadow[i]);
        g[0][i + 2] = d;
        g[i + 2][0] = d;
      }

      for (int i = 0; i < n; i++) {
        double d = distCircle(out, shadow[i]);
        g[1][i + 2] = d;
        g[i + 2][1] = d;
      }

      //for (int i = 0; i < V; i++) {for (int j = 0; j < V; j++) cout << g[]}

      double ans = dijkstra(0, 1);
      cout << "Shortest sun distance is " << fixed << setprecision(1) << ans << "." << endl;
    }
  }
  return 0;
}