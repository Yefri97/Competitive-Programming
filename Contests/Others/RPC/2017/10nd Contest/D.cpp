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
typedef pair<int, vi> ii;
typedef vector<ii> vii;

const int oo = 1e9, mxn = 510;

int A[mxn][mxn];

vi getMin(vi v) {
	vi ans = v;
	fori(i, 1, 4) {
		vi x(4);
		fori(j, 0, 4) x[j] = v[(i + j) % 4];
		ans = min(ans, x);
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, k;
	while (cin >> n >> k && n) {
		priority_queue<ii> tiles;
		fori(i, 0, k) {
			vi v(4);
			cin >> v[0] >> v[1] >> v[3] >> v[2];
			int w; cin >> w;
			tiles.push(ii(w, getMin(v)));
		}
		fori(i, 0, n)
			fori(j, 0, n)
				cin >> A[i][j];
		int cnt = 0;
		map<vi, int> board;
		fori(i, 0, n / 2) {
			fori(j, 0, n / 2) {
				vi v = {A[2 * i][2 * j], A[2 * i][2 * j + 1], A[2 * i + 1][2 * j + 1], A[2 * i + 1][2 * j]};
				board[getMin(v)]++;
				cnt++;
			}
		}
		int ans = 0;
		while (cnt && !tiles.empty()) {
			ii top = tiles.top(); tiles.pop();
			int w = top.first;
			vi tile = top.second;
			if (board[tile] != 0) {
				board[tile]--;
				ans += w;
				cnt--;
			}
		}
		cout << (cnt ? -1 : ans) << endl;
	}
	return 0;
}