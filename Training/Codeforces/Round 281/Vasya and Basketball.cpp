// Sweep line
#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	priority_queue<ii> pq;
	int n; cin >> n;
	fori(i, 0, n) {
		int x; cin >> x;
		pq.push(ii(-x, 1));
	}
	int m; cin >> m;
	fori(i, 0, m) {
		int x; cin >> x;
		pq.push(ii(-x, 0));
	}
	vi cnt(2);
	int max_val = 3 * n - 3 * m;
	ii ans = ii(3 * n, 3 * m);
	while (!pq.empty()) {
		ii top = pq.top(); pq.pop();
		cnt[1 - top.second]++;
		int score1 = 2 * cnt[0] + 3 * (n - cnt[0]);
		int score2 = 2 * cnt[1] + 3 * (m - cnt[1]);
		int val = score1 - score2;
		if (val > max_val) {
			max_val = val;
			ans = ii(score1, score2);
		}
	}
	cout << ans.first << ":" << ans.second << endl;
	return 0;
}
