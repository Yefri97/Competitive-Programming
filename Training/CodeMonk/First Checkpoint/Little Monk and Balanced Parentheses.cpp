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

	int n; cin >> n;
	vi v(n), c(n);
	fori(i, 0, n)
		cin >> v[i];

	stack<ii> s;
	fori(i, 0, n) {
		int x = v[i];
		if (x > 0) {
			s.push(ii(x, i));
		} else {
			if (!s.empty()) {
				ii t = s.top(); s.pop();
				if (abs(x) == t.first) {
					c[i] = 1;
					c[t.second] = 1;
				} else {
					while (!s.empty())
						s.pop();
				}
			}
		}
	}

	int ans = 0, cnt = 0;
	fori(i, 0, n) {
		if (c[i] == 0)
			cnt = 0;
		else
			cnt++;
		ans = max(ans, cnt);
	}

	cout << ans << endl;

	return 0;
}