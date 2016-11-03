#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MAX_N = 1e6;

struct myStack {
  int id;
  int arr[MAX_N + 10];

  myStack() : id(0) {}

  void push(int num) {
    arr[id++] = num;
  }

  int pop() {
    return arr[--id];
  }

};

int main() {
  ifstream cin("stack.in");
  ofstream cout("stack.out");
  myStack s;
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