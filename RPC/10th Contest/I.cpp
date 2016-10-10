/*
 *  RPC 10-th Contest 2016
 *  Problem I: Recurrences
 *  Status: Accepted
 */

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

const int MAX_N = 4;
struct Matrix { int mat[MAX_N][MAX_N]; };

int mod(int n, int m) { return (n % m + m) % m; }

Matrix matMul(Matrix a, Matrix b) {
  Matrix ans; int i, j, k;
  for (i = 0; i < MAX_N; i++)
    for (j = 0; j < MAX_N; j++)
      for (ans.mat[i][j] = k = 0; k < MAX_N; k++)
        ans.mat[i][j] = mod(ans.mat[i][j] + a.mat[i][k] * b.mat[k][j], 10);
  return ans;
}

Matrix matPow(Matrix base, ll p) {
  Matrix ans; int i, j;
  for (i = 0; i < MAX_N; i++)
    for (j = 0; j < MAX_N; j++)
      ans.mat[i][j] = (i == j);
  while (p) {
    if (p & 1) ans = matMul(ans, base);
    base = matMul(base, base);
    p >>= 1;
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  Matrix coef = { 1, 1, 1, 1,
                  0, 4, -3, -3,
                  0, 5, -4, -4,
                  0, -1, 1, 0   };
  int t; cin >> t;
  while (t--) {
    ll n; int Ao, Bo, Co; cin >> n >> Ao >> Bo >> Co;
    int A = mod( 4 * Ao - 3 * Bo - 3 * Co, 10);
    int B = mod( 5 * Ao - 4 * Bo - 4 * Co, 10);
    int C = mod(-1 * Ao + 1 * Bo + 0 * Co, 10);
    Matrix mp = matPow(coef, (n - 1) % 15);
    int cb[MAX_N] = {0, A, B, C}, ans[MAX_N] = {0, 0, 0, 0};
    for (int i = 0; i < MAX_N; i++)
      for (int k = 0; k < MAX_N; k++)
        ans[i] = mod(ans[i] + mp.mat[i][k] * cb[k], 10);
    cout << mod(ans[0] + ans[1] + ans[2] + ans[3], 10) << endl;
  }
  return 0;
}