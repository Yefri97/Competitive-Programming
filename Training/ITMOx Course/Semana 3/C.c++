/*
 *  ITMOx Course - 2nd Week Problems
 *  Problem: Queue with Minimum
 *  Level: Medium
 */
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int kInf = 1e9;

struct minQueue {
  int minIn;
  stack<int> input, smin;

  minQueue() : minIn(kInf) {}
  
  void push(int x) {
    minIn = min(minIn, x);
    input.push(x);
  }

  void update() {
    while (!input.empty()) {
      int x = input.top(); input.pop();
      if (smin.empty() or x < smin.top())
        smin.push(x);
      else
        smin.push(smin.top());
    }
    minIn = kInf;
  }

  void pop() {
    if (smin.empty())
      update();
    smin.pop();
  }

  int qmin() {
    if (smin.empty())
      update();
    return min(minIn, smin.top());
  }
};

int main() {
  ios::sync_with_stdio(false);  // Fast input - output
  ifstream fin("input.txt");    // File Input
  ofstream fout("output.txt");  // File Output
  /*** Code ***/
  minQueue mq;
  int n; fin >> n;
  while (n--) {
    char q; fin >> q;
    if (q == '+') {
      int x; fin >> x;
      mq.push(x);
    }
    if (q == '-') {
      mq.pop();
    }
    if (q == '?') {
      fout << mq.qmin() << endl;
    }
  }
  return 0;
}