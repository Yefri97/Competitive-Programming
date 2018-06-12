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
	int n, m; cin >> n >> m;
	vector<string> v(n);
	fori(i, 0, n)
		cin >> v[i];
	vi cnt(m);
	fori(i, 0, n)
		fori(j, 0, m)
			cnt[j] += (v[i][j] == '1');
	int ans = 0;
	fori(i, 0, n) {
		int ok = 1;
		fori(j, 0, m)
			if (v[i][j] == '1')
				ok &= (cnt[j] > 1);
		ans |= ok;
	}
	cout << (ans ? "YES" : "NO") << endl;
	return 0;
}
