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

const int oo = 1e9, mxn = 5010;
ll A[mxn], memo[mxn][mxn];

int n, m;

ll solver(int id, int k) {
	if (k == 0) return 0;
	if(memo[id][k] != -1) return memo[id][k];
	if (id + k * m > n) return memo[id][k] = 0;
	return memo[id][k] = max(solver(id + 1, k), solver(id + m, k - 1) + A[id + m - 1] - (id ? A[id - 1] : 0));
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int k; cin >> n >> m >> k;
	fori(i, 0, n)
		cin >> A[i];
	fori(i, 1, n)
		A[i] += A[i - 1];
	memset(memo, -1, sizeof memo);
	ll ans = solver(0, k);
	cout << ans << endl;
	return 0;
}