#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<int, int> ii;

const int oo = 1e9, MX = 1e3 + 10;

ll A[MX][MX];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, m; cin >> n >> m;
	fori(i, 0, n)
		fori(j, 0, m)
			cin >> A[i][j];

	vi v(4);
	fori(i, 0, 4)
		cin >> v[i];

	vi ans(2);

	fori(i, 0, n) {
		vi sum(2);
		fori(j, 0, m) {
			sum[0] += abs(A[i][j]);
			sum[1] += abs(A[i][j] + v[0]);
		}
		ans[0] += max(sum[0], max(sum[1], m * abs(v[1])));
	}

	fori(j, 0, m) {
		vi sum(2);
		fori(i, 0, n) {
			sum[0] += abs(A[i][j]);
			sum[1] += abs(A[i][j] + v[2]);
		}
		ans[1] += max(sum[0], max(sum[1], n * abs(v[3])));
	}

	cout << max(ans[0], ans[1]) << endl;

	return 0;
}