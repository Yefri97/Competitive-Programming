#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9, MN = 5010;

ll a[MN];

ll sum(int r, int l) { return a[r] - (l > 0 ? a[l - 1] : 0); }

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, k; cin >> n >> k;
	fori(i, 0, n)
		cin >> a[i];
	fori(i, 1, n)
		a[i] += a[i - 1];
	int bj = k - 1, bi = 0;
	fori(i, 0, n - k + 1) {
		fori(j, i + k - 1, n) {
			if (sum(j, i) * (bj - bi + 1) > sum(bj, bi) * (j - i + 1))
				bj = j, bi = i;
		}
	}
	double ans = sum(bj, bi) * 1.0 / (bj - bi + 1);
	cout << fixed << setprecision(10) << ans << endl;
	return 0;
}
