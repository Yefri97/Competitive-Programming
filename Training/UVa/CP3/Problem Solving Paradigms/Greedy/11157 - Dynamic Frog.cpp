#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl;
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int INF = 1e9, MAXN = 101;

char s[MAXN];
int m[MAXN];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int t, cs = 0; cin >> t;
  while (t--) {
  	int n, d; cin >> n >> d;
  	char b;
  	s[0] = 'B'; m[0] = 0;
  	for (int i = 1; i <= n; i++) {
  		cin >> s[i];
  		cin >> b;
  		cin >> m[i];
  	}
  	s[n+1] = 'B'; m[n+1] = d;
  	int ans = 0;
  	for (int i = 0; i < n + 1; i++) {
  		if (s[i + 1] == 'B')
  			ans = max(ans, abs(m[i] - m[i + 1]));
  		else
  			ans = max(ans, abs(m[i] - m[i + 2]));
  	}
  	cout << "Case " << ++cs << ": " << ans << endl;
  }
  return 0;
}