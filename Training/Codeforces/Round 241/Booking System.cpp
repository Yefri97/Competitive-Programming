#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

struct Group {
	int money, num, id;
	Group() {}
	Group(int _m, int _n, int _i) : money(_m), num(_n), id(_i) {}
	bool operator < (Group o) { return money > o.money; }
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	vector<Group> v(n);
	fori(i, 0, n) {
		int a, b; cin >> a >> b;
		v[i] = Group(b, a, i);
	}
	sort(v.begin(), v.end());
	set<ii> s;
	int q; cin >> q;
	fori(i, 0, q) {
		int k; cin >> k;
		s.insert(ii(k, i));
	}
	vector<ii> ans;
	int acc = 0;
	fori(i, 0, n) {
		auto it = s.lower_bound(ii(v[i].num, -1));
		if (it == s.end()) continue;
		acc += v[i].money;
		ans.push_back(ii(v[i].id, (*it).second));
		s.erase(it);
	}
	int m = ans.size();
	cout << m << " " << acc << endl;
	fori(i, 0, m)
		cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;
	return 0;
}
