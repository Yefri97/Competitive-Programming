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

const int oo = 1e9, mxn = 100010;

int A[2][mxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	fori(i, 0, n) {
		int x; cin >> x; x--;
		A[x][i] = 1;
	}
	fori(i, 0, 2)
		fori(j, 1, n)
			A[i][j] += A[i][j-1];
	vii ans;
	fori(t, 1, n + 1) {
		int s_a = 0, s_b = 0, curr_a = 0, curr_b = 0;
		while (true) {
			int a = lower_bound(A[0], A[0] + n, curr_a + t) - A[0];
			int b = lower_bound(A[1], A[1] + n, curr_b + t) - A[1];
			if (a == b) break;
			if (a < b) {
				s_a++;
				if (a == n - 1) {
					if (s_a > s_b) ans.push_back(ii(s_a, t));
					break;
				}
				curr_a = A[0][a], curr_b = A[1][a];
			} else {
				s_b++;
				if (b == n - 1) {
					if (s_b > s_a) ans.push_back(ii(s_b, t));
					break;
				}
				curr_a = A[0][b], curr_b = A[1][b];
			}
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << endl;
	fori(i, 0, ans.size())
		cout << ans[i].first << " " << ans[i].second << endl;
	return 0;
}