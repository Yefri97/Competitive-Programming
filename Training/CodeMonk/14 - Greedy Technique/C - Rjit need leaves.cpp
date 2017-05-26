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
  int t; cin >> t;
  while (t--) {
  	int ans = 0;
  	map<int, int> mp;
  	int n, k; cin >> n >> k;
  	fori(i, 0, n) {
  		int x; cin >> x;
  		if (mp[x + 1] == 0)
  			ans++;
  		else
  			mp[x + 1]--;
  		mp[x]++;
  	}
  	if (k - ans < 0)
  		cout << -1 << endl;
  	else
  		cout << k - ans << endl;
  }
  return 0;
}