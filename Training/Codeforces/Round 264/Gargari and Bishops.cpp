#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9, MN = 2010;

ll A[MN][MN], diag1[2 * MN], diag2[2 * MN];

ll calculate(ii x) {
	int i = x.first, j = x.second;
	return diag1[i + j] + diag2[i - j + MN] - A[i][j];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	fori(i, 0, n)
		fori(j, 0, n)
			cin >> A[i][j];
	fori(i, 0, n) {
		fori(j, 0, n) {
			diag1[i + j] += A[i][j];
			diag2[i - j + MN] += A[i][j];
		}
	}
	vector<ii> ans(2);
	ans[0] = ii(0, 0); ans[1] = ii(0, 1);
	fori(i, 0, n) {
		fori(j, 0, n) {
			int tp = (i + j) % 2;
			if (calculate(ii(i, j)) > calculate(ans[tp]))
				ans[tp] = ii(i, j);
		}
	}
	ll acc = calculate(ans[0]) + calculate(ans[1]);
	cout << acc << endl;
	fori(i, 0, 2)
		cout << ans[i].first + 1 << " " << ans[i].second + 1 << " ";
	cout << endl;
	return 0;
}
