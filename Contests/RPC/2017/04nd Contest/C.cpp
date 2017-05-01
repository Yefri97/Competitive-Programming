/*
 *  RPC 04st Contest 2017
 *  Problem C: Cable Way
 *  Outcome: Accepted | Category: Data Structure - Stack
 */
#include <bits/stdc++.h>
#define endl '\n'
#define SQ(X) ((X) * (X))
using namespace std;

typedef pair<int, double> ii;

struct point {
  int id;
  long long x, y;
  point() {}
  point(int _id, long long _x, long long _y) : id(_id), x(_x), y(_y) {}
};

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout << fixed << setprecision(4);
  int n; cin >> n;
  vector<point> input(n + 2);
  for (int i = 0; i < n + 2; i++) {
    long long x, y; cin >> x >> y;
    input[i] = point(i, x, y);
  }
  vector<ii> left(n), right(n);
  stack<point> sl, sr;
  
  sl.push(input[0]);
  for (int i = 1; i < n + 1; i++) {
    point curr = input[i];
    while (true) {
      if (sl.top().y > curr.y) break;
      sl.pop();
    }
    point taller = sl.top();
    left[i - 1].first = taller.id;
    left[i - 1].second = sqrt(SQ(taller.x - curr.x) + SQ(taller.y - curr.y));
    sl.push(curr);
  }
  
  sr.push(input[n + 1]);
  for (int i = n; i > 0; i--) {
    point curr = input[i];
    while (true) {
      if (sr.top().y > curr.y) break;
      sr.pop();
    }
    point taller = sr.top();
    right[i - 1].first = taller.id;
    right[i - 1].second = sqrt(SQ(taller.x - curr.x) + SQ(taller.y - curr.y));
    sr.push(curr);
  }

  for (int i = 0; i < n; i++)
    cout << left[i].first << " " << right[i].first << " " << left[i].second << " " << right[i].second << endl;

  return 0;
}