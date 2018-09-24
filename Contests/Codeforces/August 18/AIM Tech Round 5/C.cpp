#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define SZ(v) (int)v.size()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef tuple<int, int, int, int> SQ;

const int oo = 1e9;

void rm(multiset<int> &dict, int x) {
	auto it = dict.find(x);
	dict.erase(it);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	multiset<int> le, ri, dw, up;
	vector<SQ> squares(n);
	fori(i, 0, n) {
		int a, b, c, d; cin >> a >> b >> c >> d;
		le.insert(-a);
		ri.insert(c);
		dw.insert(-b);
		up.insert(d);
		squares[i] = SQ(a, b, c, d);
	}
	ii ans;
	fori(i, 0, n) {
		int a, b, c, d;
		tie(a, b, c, d) = squares[i];
		rm(le, -a);
		rm(ri, c);
		rm(dw, -b);
		rm(up, d);
		if (-(*le.begin()) <= *ri.begin() && -(*dw.begin()) <= *up.begin())
			ans = ii(*ri.begin(), *up.begin());
		le.insert(-a);
		ri.insert(c);
		dw.insert(-b);
		up.insert(d);
	}
	cout << ans.first << " " << ans.second << endl;
	return 0;
}
