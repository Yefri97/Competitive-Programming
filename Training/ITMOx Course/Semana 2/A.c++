/*
 *  ITMOx Course - 1st Week Problems
 *  Problem: A + B
 *  Level: Easy
 */
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
  ios::sync_with_stdio(false);  // Fast input - output
  ifstream fin("input.txt");    // File Input
  ofstream fout("output.txt");  // File Output
  /*** Code ***/
  int a, b;
  fin >> a >> b;
  fout << a + b << endl;
  return 0;
}