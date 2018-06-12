/*
 *  ITMOx Course - 2nd Week Problems
 *  Problem: Stack
 *  Level: Easy
 */
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MAX_N = 1e6;

struct myStack {
  int id;
  int arr[MAX_N + 10];
  myStack() : id(0) {}
  void push(int num) { arr[id++] = num; }
  int pop() { return arr[--id]; }
};

int main() {
  ios::sync_with_stdio(false);  // Fast input - output
  ifstream fin("input.txt");    // File Input
  ofstream fout("output.txt");  // File Output
  /*** Code ***/
  myStack s;
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