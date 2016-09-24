/*
 *  RPC 9-th Contest 2016
 *  Problem F: Factorial Products
 *  Status: Accepted
 */

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const double EPS = 1e-4;
const int MAX_N = 3000;

bool cmp(double a, double b) {
  return (abs(a - b) > EPS && (a > b));
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  double fact[MAX_N]; fact[0] = fact[1] = 0.0;
  for (int i = 2; i < MAX_N; i++)
    fact[i] = fact[i - 1] + log2(double(i));
  int t, cs = 0; cin >> t;
  while (t--) {
    cout << "Case #" << ++cs << ": ";
    int s[5]; cin >> s[0] >> s[1] >> s[2];
    double num[5]; num[0] = num[1] = num[2] = 0;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < s[i]; j++) {
        int x; cin >> x;
        num[i] += fact[x];
      }
    }
    double a = num[0], b = num[1], c = num[2];
    string ans;
    if (cmp(a, b) && cmp(a, c))
      ans = "A";
    else if (cmp(b, a) && cmp(b, c))
      ans = "B";
    else if (cmp(c, a) && cmp(c, b))
      ans = "C";
    else
      ans = "TIE";
    cout << ans << endl;
  }
  return 0;
}