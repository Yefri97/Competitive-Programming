/*
 *  RPC 04st Contest 2017
 *  Problem K: King of Music
 *  Outcome: Accepted | Category: Data Structures - rmqQueue
 */
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int kInf = 10000000;

struct rmqQueue {
  int minIn, maxIn;
  stack<int> input, smin, smax;

  rmqQueue() : minIn(kInf), maxIn(-1) {}
  
  void push(int x) {
    minIn = min(minIn, x);
    maxIn = max(maxIn, x);
    input.push(x);
  }

  void update() {
    while (!input.empty()) {
      int x = input.top(); input.pop();
      
      if (smin.empty() or x < smin.top())
        smin.push(x);
      else
        smin.push(smin.top());
        
      if (smax.empty() or x > smax.top())
        smax.push(x);
      else
        smax.push(smax.top());  
    }
    minIn = kInf;
    maxIn = -1;
  }

  void pop() {
    if (smin.empty())
      update();
    smin.pop();
    smax.pop();
  }

  int queryMin() {
    if (smin.empty())
      update();
    return min(minIn, smin.top());
  }
  
  int queryMax() {
    if (smax.empty())
      update();
    return max(maxIn, smax.top());
  }
};

bool solver(vector<int> &v, int n, int w, int k) {
  rmqQueue rq;
  for (int i = 0; i < w; i++)
    rq.push(v[i]);
  for (int i = w; i < n; i++) {
    if (rq.queryMin() < v[i] - k or rq.queryMax() > v[i] + k)
      return false;
    rq.pop();
    rq.push(v[i]);
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n, w, k;
  while (cin >> n >> w >> k and (n or w or k)) {
    vector<int> input(n);
    for (int i = 0; i < n; i++)
      cin >> input[i];
    bool ans = solver(input, n, w, k);
    cout << ((ans)? "Yes." : "No.") << endl;
  }
  return 0;
}
