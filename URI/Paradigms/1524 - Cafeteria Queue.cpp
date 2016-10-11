#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1000;

int main() {
  int v[MAX_N + 10];
  int n, k;
  while (cin >> n >> k) {
    priority_queue<int> pq;
    for (int i = 0; i < n - 1; i++) {
      int x; cin >> x;
      v[i] = x;
      if (i > 0) x -= v[i - 1];
      pq.push(x);
    }
    int ans = v[n - 2];
    for (int i = 0; i < k - 1; i++) {
      int front = pq.top(); pq.pop();
      ans -= front;
    }
    cout << ans << endl;
  }
}