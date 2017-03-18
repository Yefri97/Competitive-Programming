#include <bits/stdc++.h>
using namespace std;

struct event {
  int id, tm, io;
  event(int _id, int _tm, int _io) : id(_id), tm(_tm), io(_io) {}
  bool operator < (event other) const {
    if (tm != other.tm)
      return tm > other.tm;
    return io;
  }
};

int main() {
  int n, k;
  while (cin >> n >> k && (n + k)) {
    priority_queue<event> pq;
    for (int i = 0; i < n; i++) {
      int x, y; cin >> x >> y;
      pq.push(event(i, x, 1));
      pq.push(event(i, y, 0));
    }
    int ok = 1;
    stack<int> st;
    while (!pq.empty()) {
      event now = pq.top(); pq.pop();
      if (now.io) {
        st.push(now.id);
      } else {
        int car_id = st.top(); st.pop();
        if (car_id != now.id) ok = 0;
      }
      if (st.size() > k) ok = 0;
      if (ok == 0) break;
    }
    cout << ((ok)? "Sim" : "Nao") << endl;
  }
  return 0;
}