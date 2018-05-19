#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9, MX = 1010;

int seen[MX];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	vi v(n);
	fori(i, 0, n)
		cin >> v[i];
	reverse(v.begin(), v.end());
	vi ans;
	fori(i, 0, n) {
		if (!seen[v[i]]) {
			ans.push_back(v[i]);
			seen[v[i]] = 1;
		}
	}
	reverse(ans.begin(), ans.end());
	cout << ans.size() << endl;
	fori(i, 0, ans.size())
		cout << ans[i] << " ";
	cout << endl;
	return 0;
}
