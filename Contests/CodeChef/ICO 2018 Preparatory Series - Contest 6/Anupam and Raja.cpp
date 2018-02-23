#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))
#define sq(x) (x) * (x)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const ll oo = 1e18, MX = 310, MD = 1e9 + 9;

ll g[MX][MX];
ll ans[MX];

void mult(ll A[2][2], ll B[2][2]) {
	ll a = A[0][0] * B[0][0] + A[0][1] * B[1][0];
	ll b = A[0][0] * B[0][1] + A[0][1] * B[1][1];
	ll c = A[1][0] * B[0][0] + A[1][1] * B[1][0];
	ll d = A[1][0] * B[0][1] + A[1][1] * B[1][1];
	A[0][0] = a % MD;
	A[0][1] = b % MD;
	A[1][0] = c % MD;
	A[1][1] = d % MD;
}

void power(ll M[2][2], int e) {
	if (e == 0 || e == 1)
		return;

	ll F[2][2] = {{1, 1}, {1, 0}};

	power(M, e >> 1);
	mult(M, M);

	if (e % 2)
		mult(M, F);
}

ll f(int n) {
	ll A[2][2] = {{4, 3}, {3, 1}};
	ll M[2][2] = {{1, 1}, {1, 0}};

	power(M, n - 1);

	if (n > 1) mult(A, M);

	return A[0][1];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, m; cin >> n >> m;
	fori(i, 0, n)
		fori(j, 0, n)
			g[i][j] = i == j ? 0LL : oo;
	while (m--) {
		int u, v, w; cin >> u >> v >> w; u--; v--;
		g[u][v] = w;
		g[v][u] = w;
	}
	fori(k, 0, n)
		fori(i, 0, n)
			fori(j, 0, n)
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
	int q; cin >> q;
	while (q--) {
		int u, k; cin >> u >> k; u--;
		ll x = (k == 1) ? 2LL : f(k - 1);
		fori(i, 0, n)
			ans[i] = (ans[i] + x + g[u][i]) % MD;
	}
	fori(i, 0, n)
		cout << ans[i] << " ";
	cout << endl;
	return 0;
}