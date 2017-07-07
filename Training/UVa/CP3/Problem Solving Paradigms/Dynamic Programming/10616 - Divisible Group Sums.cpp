// 0-1 Knapsack (Subset Sum)
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

const int INF = 1e9;
int n, m, d;
ll A[210], memo[210][15][25];

ll solver(int id, int k, int acc) {
	if (k == m) { return acc == 0; }
	if (id == n) return 0;
	if (memo[id][k][acc] != -1) return memo[id][k][acc];
	return memo[id][k][acc] = solver(id + 1, k, acc) + solver(id + 1, k + 1, mod(acc + A[id], d));
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int q, cs = 0;
	while (cin >> n >> q && (n || q)) {
		fori(i, 0, n)
			cin >> A[i];
		cout << "SET " << ++cs << ":" << endl;
		fori(i, 0, q) {
			cin >> d >> m;
			memset(memo, -1, sizeof memo);
			ll ans = solver(0, 0, 0);
			cout << "QUERY " << i + 1 << ": " << ans << endl;
		}
	}
	return 0;
}