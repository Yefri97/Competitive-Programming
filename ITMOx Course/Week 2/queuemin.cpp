#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
  ifstream cin("queuemin.in");
  ofstream cout("queuemin.out");

  deque<int> dq;
  queue<int> q;
  int t; cin >> t;
  while (t--) {
    char c; cin >> c;
    if (c == '+') {
      int x; cin >> x;
      while (!dq.empty()) {
        if (dq.back() <= x) break;
        dq.pop_back(); 
      }
      dq.push_back(x);
      q.push(x);
    } else if (c == '-') {
      if (q.front() == dq.front()) dq.pop_front();
      q.pop();
    } else {
      cout << dq.front() << endl;
    }
  }

  return 0;
}