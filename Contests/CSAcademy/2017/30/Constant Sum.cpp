#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl;
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int INF = 1e9, MAXN = 100010;
int input[MAXN];
ll add[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, m; cin >> n >> m;
	fori(i, 0, n)
		cin >> input[i];
	memset(add, 0, sizeof add);
	ll acc_s = 0;
	while (m--) {
		int q; cin >> q;
		if (q == 0) {
			int i, s; cin >> i >> s; i--;
			add[i] += s;
			acc_s += s;
		} else {
			int i; cin >> i; i--;
			cout << fixed << setprecision(10) << input[i] + (double)(n * add[i] - acc_s) / (n - 1) << endl;
		}
	}
	return 0;
}