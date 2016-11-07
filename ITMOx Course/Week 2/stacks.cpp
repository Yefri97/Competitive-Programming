#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
  ifstream cin("stacks.in");
  ofstream cout("stacks.out");

  int n; cin >> n;
  vector<int> input(n);
  for (int i = 0; i < n; i++) cin >> input[i];
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
  cout << mmax << endl;
  return 0;
}