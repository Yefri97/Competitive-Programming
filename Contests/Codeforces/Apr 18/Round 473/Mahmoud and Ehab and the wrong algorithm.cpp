#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
  if (n > 5) {
    cout << 1 << " " << 2 << endl;
    for (int i = 3; i <= n; i++)
      cout << 2 - (i % 2) << " " << i << endl;
  } else {
    cout << -1 << endl;
  }
  fori(i, 1, n)
    cout << i << " " << i + 1 << endl;
	return 0;
}
