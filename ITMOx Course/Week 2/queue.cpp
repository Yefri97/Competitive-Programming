#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MAX_N = 1e6;

struct myQueue {
  int front;
  int last;
  int arr[MAX_N + 10];

  myQueue() : front(0), last(0) {}

  void push(int num) {
    arr[last++] = num;
  }

  int pop() {
    return arr[front++];
  }

};

int main() {
  ifstream cin("queue.in");
  ofstream cout("queue.out");
  myQueue s;
  int n; cin >> n;
  while (n--) {
    char c; cin >> c;
    if (c == '-') {
      cout << s.pop() << endl;
    } else {
      int x; cin >> x;
      s.push(x);
    }
  }
  return 0;
}