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
	int tc; cin >> tc;
	fori(t, 0, tc) {
		int n; cin >> n;
		vector<vi> v(2);
		fori(i, 0, n) {
			int x; cin >> x;
			v[i % 2].push_back(x);
		}
		sort(v[0].begin(), v[0].end());
		sort(v[1].begin(), v[1].end());
		int ans = -1;
		fori(i, 0, n - 1) {
			int j = i + 1;
			if (ans == -1 && v[j % 2][j / 2] < v[i % 2][i / 2])
				ans = i;
		}
		cout << "Case #" << t + 1 << ": ";
		if (ans == -1) cout << "OK" << endl;
		else cout << ans << endl;
	}
	return 0;
}
