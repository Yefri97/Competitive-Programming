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

const int oo = 1e9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int x, y, a, b; cin >> x >> y >> a >> b;
	vii ans;
	for (int i = 1; i <= x; i++)
		for (int j = 1; j <= y; j++)
			if (i > j && i >= a && j >= b)
				ans.push_back(ii(i, j));
	cout << ans.size() << endl;
	fori(i, 0, ans.size())
		cout << ans[i].first << " " << ans[i].second << endl;
	return 0;
}