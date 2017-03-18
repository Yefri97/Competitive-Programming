/*
 *  RPC 01st Contest 2017
 *  Problem A: Blur
 *  Status: Accepted
 */

#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cout << #x << ": " << x << endl
#define endl '\n'
const int MX = 105;

int mx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int my[] = {0, 1, 1, 1, 0, -1, -1, -1};


struct fraction{
  long long n, d;
  
  fraction(){}
  fraction(long long x) {
    n = x; d = 1;
  }
  fraction(long long x, long long y) {
    y = max(1ll, y);
    long long g = __gcd(x, y);
    n = x / g;
    d = y / g;
  }
  
  fraction operator +(const fraction &t) {
    return fraction(n * t.d + t.n * d, d * t.d);
  }
  
  fraction operator *(const fraction &t) {
    return fraction(n * t.d, d * t.n);
  }
  
  bool operator <(const fraction &t) const{
    return n * t.d < t.n * d;
  }
  
};

fraction mat[MX][MX], tmp[MX][MX];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int n, m, r, x;
  while (cin >> n >> m >> r) {
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        cin >> x;
        mat[i + 1][j + 1] = fraction(x);
      }
    }
    for (int i = 1; i <= n; i++) {
      mat[m + 1][i] = mat[1][i]; 
      mat[0][i] = mat[m][i];
    }
    for (int i = 1; i <= m; i++) { 
      mat[i][0] = mat[i][n];
      mat[i][n + 1] = mat[i][1];
    }
    mat[0][0] = mat[m][n];
    mat[0][n + 1] = mat[m][1];
    mat[m + 1][0] = mat[1][n];
    mat[m + 1][n + 1] = mat[1][1];
    
    
    for (int k = 0; k < r; k++){
      for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
          fraction top(mat[i][j]);
          for (int l = 0; l < 8; l++) {
            int xx = i + mx[l];
            int yy = j + my[l];
            top = top + mat[xx][yy];
          }
          tmp[i][j] = top * fraction(1, 9);
        }
      }
      
      
      for (int i = 1; i <= n; i++) {
        tmp[m + 1][i] = tmp[1][i]; 
        tmp[0][i] = tmp[m][i];
      }
      for (int i = 1; i <= m; i++) { 
        tmp[i][0] = tmp[i][n];
        tmp[i][n + 1] = tmp[i][1];
      }
      tmp[0][0] = tmp[m][n];
      tmp[0][n + 1] = tmp[m][1];
      tmp[m + 1][0] = tmp[1][n];
      tmp[m + 1][n + 1] = tmp[1][1];
      
      for (int i = 0; i <= m + 1; i++) {
        for (int j = 0; j <= n + 1; j++)
          mat[i][j] = tmp[i][j];
      }
    }
    set<fraction> ans;
    for (int i = 0; i <= m + 1; i++) {
        for (int j = 0; j <= n + 1; j++)
          ans.insert(mat[i][j]);
      }
    cout << ans.size() << endl;
  }
}
