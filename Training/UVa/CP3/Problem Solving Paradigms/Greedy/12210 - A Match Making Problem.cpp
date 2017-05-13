#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl;
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int INF = 1e9;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n, m, t = 1;
  while (cin >> n >> m && (n || m)) {
  	int minval = 100;
  	for (int i = 0; i < n; i++) {
  		int x; cin >> x;
  		minval = min(minval, x);
  	}
  	for (int i = 0; i < m; i++) {
  		int x; cin >> x;
  	}
  	cout << "Case " << t++ << ": ";
  	if (n > m)
  		cout << n - m << " " << minval << endl;
  	else
  		cout << 0 << endl;
  }
  return 0;
}