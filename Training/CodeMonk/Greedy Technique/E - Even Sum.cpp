#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl;
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int INF = 1e9, MAXN = 100010, MOD = 1e9 + 7;
int input[MAXN];
ll suba_left[MAXN], suba_right[MAXN];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n; cin >> n;
  fori(i, 0, n)
  	cin >> input[i];
  int count_zero = 1, count_one = 0;
  for (int i = 0, prev = 0, curr = 0; i < n; i++, prev = curr) {
  	curr = (prev + input[i] % 2) % 2;
  	if (curr == 0) {
  		suba_left[i] = count_zero;
  		count_zero++;
  	} else {
  		suba_left[i] = count_one;
  		count_one++;
  	}
  }
  count_zero = 1, count_one = 0, suba_right[n] = 0;
  for (int i = n - 1, prev = 0, curr = 0; i >= 0; i--, prev = curr) {
  	curr = (prev + input[i] % 2) % 2;
  	if (curr == 0) {
  		suba_right[i] = (suba_right[i + 1] + count_zero) % MOD;
  		count_zero++;
  	} else {
  		suba_right[i] = (suba_right[i + 1] + count_one) % MOD;
  		count_one++;
  	}
  }
  int ans = 0;
  fori(i, 0, n)
  	ans = (ans + ((suba_left[i] * suba_right[i + 1]) % MOD)) % MOD;
  cout << ans << endl;
  return 0;
}