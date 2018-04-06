#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9, MN = 210;

int A[MN][MN], S[MN][MN];

int sum(int i1, int j1, int i2, int j2) {
  return S[i1][j1] - S[i1][j2 - 1] - S[i2 - 1][j1] + S[i2 - 1][j2 - 1];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

  int n, m, k; cin >> n >> m >> k;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      cin >> A[i][j];

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      S[i][j] = A[i][j] + S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1];

  int mx_val = 0;

  for (int i1 = k; i1 <= n; i1++) {
    for (int j1 = k; j1 <= m; j1++) {
      for (int i2 = i1 - k + 1; i2 <= i1; i2++) {
        for (int j2 = j1 - k + 1; j2 <= j1; j2++) {
          if (j2 - k + 1 > 0 && i2 + k - 1 <= n) {
            int x = 0;
            x += sum(i1, j1, i1 - k + 1, j1 - k + 1);
            x += sum(i2 + k - 1, j2, i2, j2 - k + 1);
            x -= sum(i1, j2, i2, j1 - k + 1);
            mx_val = max(mx_val, x);
          }
          if (j2 + k - 1 <= m && i2 + k - 1 <= n) {
            int x = 0;
            x += sum(i1, j1, i1 - k + 1, j1 - k + 1);
            x += sum(i2 + k - 1, j2 + k - 1, i2, j2);
            x -= sum(i1, j1, i2, j2);
            mx_val = max(mx_val, x);
          }
        }
      }
    }
  }

  int mx1 = 0;
  for (int i = k; i + k - 1 <= n; i++) {
    for (int j = k; j <= m; j++) {
      mx_val = max(mx_val, mx1 + sum(i + k - 1, j, i, j - k + 1));
    }
    for (int j = k; j <= m; j++) {
      mx1 = max(mx1, sum(i, j, i - k + 1, j - k + 1));
    }
  }

  int mx2 = 0;
  for (int j = k; j + k - 1 <= m; j++) {
    for (int i = k; i <= n; i++) {
      mx_val = max(mx_val, mx2 + sum(i, j + k - 1, i - k + 1, j));
    }
    for (int i = k; i <= n; i++)
      mx2 = max(mx2, sum(i, j, i - k + 1, j - k + 1));
  }

  cout << n * m - S[n][m] + mx_val << endl;

	return 0;
}
