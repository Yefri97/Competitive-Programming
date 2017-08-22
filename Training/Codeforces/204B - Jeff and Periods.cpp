#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int INF = 1e9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	vector<ii> v(n);
	fori(i, 0, n) {
		int x; cin >> x;
		v[i] = ii(x, i);
	}
	sort(v.begin(), v.end());
	v.push_back(ii(INF, -1));
	vector<ii> ans;
	fori(i, 0, n) {
		int x = v[i].first;
		if (x == v[i + 1].first) {
			int d = v[i + 1].second - v[i].second;
			bool flag = true;
			while (x == v[i + 1].first) {
				flag &= (v[i + 1].second - v[i].second == d);
				i++;
			}
			if (flag)
				ans.push_back(ii(x, d));
		} else {
			ans.push_back(ii(x, 0));
		}
		
	}
	cout << ans.size() << endl;
	fori(i, 0, ans.size())
		cout << ans[i].first << " " << ans[i].second << endl;
	return 0;
}