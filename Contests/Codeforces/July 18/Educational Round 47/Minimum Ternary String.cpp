#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define SZ(v) (int)v.size()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	string s; cin >> s;
	int cnt = 0;
	string ans;
	for (char c : s) {
		if (c == '1')
			cnt++;
		else
			ans.push_back(c);
	}
	int idx = 0;
	while (idx < SZ(ans) && ans[idx] == '0')
		idx++;
	cout << ans.substr(0, idx);
	cout << string(cnt, '1');
	cout << ans.substr(idx, SZ(ans) - idx) << endl;
	return 0;
}
