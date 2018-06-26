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
	vi v(n);
	fori(i, 0, n)
		cin >> v[i];
	vi a(n);
	fori(i, 0, m) {
		int x; cin >> x;
		fori(j, 0, n)
			if (v[j] == x)
				a[j] = 1;
	}
	vi ans;
	fori(i, 0, n)
		if (a[i])
			ans.push_back(v[i]);
	fori(i, 0, ans.size())
		cout << ans[i] << " ";
	cout << endl;
	return 0;
}
