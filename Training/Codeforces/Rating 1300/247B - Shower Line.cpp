#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int INF = 1e9, MAXN = 5;
int g[MAXN][MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	fori(i, 0, 5)
		fori(j, 0, 5)
			cin >> g[i][j];
	vi v(5);
	fori(i, 0, 5) v[i] = i;
	int ans = -1;
	do {
		int a = v[0], b = v[1], c = v[2], d = v[3], e = v[4];
		int val = g[a][b] + g[b][a] + 2 * g[c][d] + 2 * g[d][c] + g[b][c] + g[c][b] + 2 * g[d][e] + 2 * g[e][d];
		ans = max(ans, val);
	} while (next_permutation(v.begin(), v.end()));
	cout << ans << endl;
	return 0;
}