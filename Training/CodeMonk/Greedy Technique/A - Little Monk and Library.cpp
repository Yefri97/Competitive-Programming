#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl;
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int INF = 1e9, MAXN = 1000001;

ll table[MAXN], shelf[MAXN];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n; cin >> n;
  fori(i, 0, n)
  	cin >> table[i];
  fori(i, 0, n)
 		cin >> shelf[i];
 	sort(table, table + n);
 	sort(shelf, shelf + n);
 	ll ans = 0;
 	fori(i, 0, n)
 		ans += abs(table[i] - shelf[i]);
 	cout << ans << endl;
  return 0;
}