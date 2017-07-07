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

const int INF = 1e9, MAXN = 210;
int n, x, t, m;
int v[MAXN], w[MAXN];
int memo[210][25][1010];

bool can(int price) { return price * 11 <= 10 * x * (n + 1) - (n + 1) * t * 11; }

int solver(int id, int k, int p) {
	if (k == 2 * (n + 1)) return 0;
	if (id == 2 * m) return 0;
	if (memo[id][k][p] != -1) return memo[id][k][p];
	if (!can(p + w[id])) return memo[id][k][p] = solver(id + 1, k, p);
	return memo[id][k][p] = max(solver(id + 1, k, p), solver(id + 1, k + 1, p + w[id]) + v[id]);
} 

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	while (cin >> n >> x >> t >> m && (n || x || t || m)) {
		fori(i, 0, m) {
			int price; cin >> price;
			w[2 * i] = w[2 * i + 1] = price;
			int acc = 0;
			fori(j, 0, n + 1) {
				int ind; cin >> ind;
				acc += ind;
			}
			v[2 * i] = v[2 * i + 1] = acc;
		}
		memset(memo, -1, sizeof memo);
		int ans = solver(0, 0, 0);
		cout << fixed << setprecision(2) << (double)ans / (n + 1.0) << endl;
	}
	return 0;
}