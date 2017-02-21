// Three or More Nested Loops, Easy
#include <bits/stdc++.h>
using namespace std;

vector<int> posibleScores() {
  set<int> s;
  for (int i = 0; i <= 20; i++)
    for (int j = 1; j <= 3; j++)
      s.insert(i * j);
  s.insert(50);
  vector<int> target;
  for (set<int>::iterator it = s.begin(); it != s.end(); it++)
    target.push_back(*it);
  return target;
}

int main() {
  vector<int> scores = posibleScores();
  int score;
  while (cin >> score && score > 0) {
    int c = 0, p = 0;
    for (int i = 0; i < scores.size(); i++)
      for (int j = i; j < scores.size(); j++)
        for (int k = j; k < scores.size(); k++)
          c += (scores[i] + scores[j] + scores[k] == score);

    for (int i = 0; i < scores.size(); i++)
      for (int j = 0; j < scores.size(); j++)
        for (int k = 0; k < scores.size(); k++)
          p += (scores[i] + scores[j] + scores[k] == score);
        
    if (c == 0) {
      cout << "THE SCORE OF " << score << " CANNOT BE MADE WITH THREE DARTS." << endl;
    } else {
      cout << "NUMBER OF COMBINATIONS THAT SCORES " << score << " IS " << c << "." << endl;
      cout << "NUMBER OF PERMUTATIONS THAT SCORES " << score << " IS " << p << "." << endl;
    }
    for (int i = 0; i < 70; i++) cout << "*"; cout << endl;
  }
  cout << "END OF OUTPUT" << endl;
  return 0;
}