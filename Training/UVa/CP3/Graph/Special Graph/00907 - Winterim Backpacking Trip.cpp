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

const int oo = 1e9, mxn = 610, mxk = 310;

int n;
int A[mxn], memo[mxn][mxk];

int solver(int id, int k) {
	if (id == n + 1) return 0;
	if (k == 0) return accumulate(A + id, A + n + 1, 0);
	if (memo[id][k] != -1) return memo[id][k];
	int ans = oo, acc = 0;
	fori(i, id + 1, n + 1) {
		acc += A[i - 1];
		ans = min(ans, max(acc, solver(i, k - 1)));
	}
	return memo[id][k] = ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int k;
	while (cin >> n >> k) {
		fori(i, 0, n + 1)
			cin >> A[i];
		memset(memo, -1, sizeof memo);
		int ans = solver(0, k);
		cout << ans << endl;
	}
	return 0;
}