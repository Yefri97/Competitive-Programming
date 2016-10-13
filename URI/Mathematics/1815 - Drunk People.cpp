#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100;
double mat[MAX_N + 10][MAX_N + 10], memo[MAX_N + 10][MAX_N + 10];
int n, t;

double solver(int u, int k) {
  if (u == t) return 1.0;
  if (k == 0) return 0.0;
  if (memo[u][k] != -1) return memo[u][k];
  double ans = 0;
  for (int v = 0; v < n; v++)
    ans += mat[u][v] * solver(v, k - 1);
  return memo[u][k] = ans;
}

int main() {
  int cs = 0;
  while (cin >> n && n) {
    cout << "Instancia " << ++cs << endl;
    int s, k; cin >> s >> t >> k; s--; t--;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
      cin >> mat[i][j];
    for (int i = 0; i < MAX_N + 10; i++) for (int j = 0; j < MAX_N + 10; j++) 
      memo[i][j] = -1.0;
    double ans = solver(s, k);
    cout << fixed << setprecision(6) << 1 - ans << endl;
    cout << endl;
  }
  return 0;
}