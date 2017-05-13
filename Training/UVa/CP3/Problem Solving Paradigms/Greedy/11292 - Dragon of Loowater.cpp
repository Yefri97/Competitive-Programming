#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl;
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int INF = 1e9, MAXN = 20010;

int d[MAXN], k[MAXN];

int solver(int n, int m) {
	int target = 0;
	int a = 0, b = 0;
	while (a < n) {
		while (b < m && k[b] < d[a]) b++;
		if (b == m) return -1;
		target += k[b];
		a++; b++;
	}
	return target;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n, m;
  while (cin >> n >> m && (n || m)) {
  	for (int i = 0; i < n; i++)
  		cin >> d[i];
  	for (int i = 0; i < m; i++)
  		cin >> k[i];
  	sort(d, d + n);
  	sort(k, k + m);
  	int ans = solver(n, m);
  	if (ans == -1)
  		cout << "Loowater is doomed!" << endl;
  	else
  		cout << ans << endl;
  }
  return 0;
}