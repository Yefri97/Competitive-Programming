#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  vector<int> score(n);
  for (int i = 0; i < score.size(); i++)
    cin >> score[i];
  int a = 0, b = 0;
  int best = score[0], worst = score[0];
  for (int i = 1; i < score.size(); i++) {
    if (score[i] > best) {
      best = score[i];
      a++;
    }
    if (score[i] < worst) {
      worst = score[i];
      b++;
    }
  }
  cout << a << " " << b << endl;
  return 0;
}