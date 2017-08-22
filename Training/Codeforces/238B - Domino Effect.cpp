#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))
#define sq(x) (x) * (x)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int oo = 1e9, mxn = 3010;

int d[mxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	string s; cin >> s;
	memset(d, -1, sizeof d);
	fori(i, 0, n) if (s[i] != '.') d[i] = 0;
	queue<ii> q;
	fori(i, 0, n) if (s[i] != '.') q.push(ii(i, (s[i] == 'L' ? -1 : 1)));
	while (!q.empty()) {
		ii u = q.front(); q.pop();
		if (d[u.first] == -1) continue;
		int v = u.first + u.second;
		if (v < 0 || v >= n) continue;
		if (d[v] == -1) {
			d[v] = d[u.first] + 1;
			q.push(ii(v, u.second));
		} else if (d[v] == d[u.first] + 1) {
			d[v] = -1;
		}
	}
	int ans = 0;
	fori(i, 0, n)
		ans += (d[i] == -1);
	cout << ans << endl;
	return 0;
}