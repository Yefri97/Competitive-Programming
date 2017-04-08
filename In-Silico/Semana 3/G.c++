/*
 *  ITMOx Cour e - 2nd Week Problems
 *  Problem: Stacks
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
  int n; fin >> n;
  vector<int> input(n);
  for (int i = 0; i < n; i++) fin >> input[i];
  input[0] = 1;
  
  int mmax = 1, it = 0;
  vector<int> stacks;
  for (int i = 0; i < n; i++) {
    if (input[i]) {
      stacks.push_back(1);
    } else {
      while (it < stacks.size() && stacks[it] == mmax) it++;
      if (it == stacks.size()) {
        it = 0;
        mmax++;
      }
      stacks[it]++;
    }
  }
  fout << mmax << endl;
  return 0;
}