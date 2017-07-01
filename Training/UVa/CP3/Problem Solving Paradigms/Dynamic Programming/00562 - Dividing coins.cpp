// 0-1 Knapsack
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

const int INF = 1e9, MAXN = 110;

int A[MAXN], memo[110][50010];
int n, acc;

int solver(int id, int val) {
	if(id == n) return abs(acc - 2 * val);
	if (memo[id][val] != -1) return memo[id][val];
	return memo[id][val] = min(solver(id + 1, val + A[id]), solver(id + 1, val));
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> n;
		fori(i, 0, n)
			cin >> A[i];
		acc = accumulate(A, A + n, 0);
		memset(memo, -1, sizeof memo);
		int ans = solver(0, 0);
		cout << ans << endl;
	}
	return 0;
}