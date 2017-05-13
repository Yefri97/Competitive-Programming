#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl;
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

#define isOn(S, j) (S & (1 << j))
#define setBit(S, j) (S |= (1 << j))
#define setAll(n) ((1 << n) - 1)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int INF = 1e9;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  unsigned int n, l, u;
  while (cin >> n >> l >> u) {
  	unsigned int target = 0;
  	for (int i = 31; i >= 0; i--) {
  		if (isOn(n, i)) {
  			if ((target | setAll(i)) < l)
  				setBit(target, i);
  		} else {
  			if (!((target | (1 << i)) > u))
  				setBit(target, i);
  		}
  	}
  	cout << target << endl;
  }
  return 0;
}