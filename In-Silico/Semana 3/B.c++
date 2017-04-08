/*
 *  ITMOx Course - 2nd Week Problems
 *  Problem: Queue
 *  Level: Easy
 */
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MAX_N = 1e6;

struct myQueue {
  int front;
  int last;
  int arr[MAX_N + 10];
  myQueue() : front(0), last(0) {}
  void push(int num) { arr[last++] = num; }
  int pop() { return arr[front++]; }
};

int main() {
  ios::sync_with_stdio(false);  // Fast input - output
  ifstream fin("input.txt");    // File Input
  ofstream fout("output.txt");  // File Output
  /*** Code ***/
  myQueue s;
  int n; fin >> n;
  while (n--) {
    char c; fin >> c;
    if (c == '-') {
      fout << s.pop() << endl;
    } else {
      int x; fin >> x;
      s.push(x);
    }
  }
  return 0;
}