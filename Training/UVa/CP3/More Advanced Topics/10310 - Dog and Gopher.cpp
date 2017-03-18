#include <bits/stdc++.h>
using namespace std;

struct point {
  double x, y;
};

double dist(point a, point b) {
  double dx = a.x - b.x;
  double dy = a.y - b.y;
  return sqrt(dx * dx + dy * dy);
}

int main() {
  int n;
  while (cin >> n) {
    point gopher, dog;
    cin >> gopher.x >> gopher.y >> dog.x >> dog.y;
    point ans; int seen = 0;
    while (n--) {
      point hole; cin >> hole.x >> hole.y;
      if (!seen && 2 * dist(gopher, hole) <= dist(dog, hole)) {
        ans = hole;
        seen = 1;
      }
    }
    if (seen)
      cout << "The gopher can escape through the hole at (" << fixed << setprecision(3) << ans.x << "," << ans.y << ")." << endl;
    else
      cout << "The gopher cannot escape." << endl;
  }
  return 0;
}