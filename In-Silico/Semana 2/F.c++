/*
 *  ITMOx Course - 1st Week Problems
 *  Problem: Write a Code Template!
 *  Level: Medium
 */
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

typedef pair<int, int> ii;

const int kInf = 1e9;

int main() {
  ios::sync_with_stdio(false);  // Fast input - output
  ifstream fin("input.txt");    // File Input
  ofstream fout("output.txt");  // File Output
  /*** Code ***/
  int w, h;
  vector<ii> keyboard(95);
  fin >> w >> h;
  for (int i = 0; i < h; i++) {
    string line; fin >> line;
    for (int j = 0; j < w; j++) {
      int c = line[j] - ' ';
      keyboard[c] = ii(i, j);
    }
  }
  
  string name_ans;
  int ans = kInf;
  for (int i = 0; i < 3; i++) {
    string name, line, code; 
    fin >> name;
    fin >> line;
    while (fin >> line && line != "\%TEMPLATE-END\%") {
      code += line;
    }

    int acc = 0;
    for (int j = 0; j < code.size() - 1; j++) {
      int curr = code[j] - ' ', next = code[j + 1] - ' ';
      acc += max(abs(keyboard[curr].first - keyboard[next].first), abs(keyboard[curr].second - keyboard[next].second));
    }
    if (acc < ans) {
      name_ans = name;
      ans = acc;
    }
  }
  
  fout << name_ans << endl;
  fout << ans << endl;
  return 0;
}