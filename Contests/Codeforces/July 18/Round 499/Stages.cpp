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
	int n, k; cin >> n >> k;
	string s; cin >> s;
	sort(s.begin(), s.end());
	s.resize(distance(s.begin(), unique(s.begin(), s.end())));
	int ans = 0;
	fori(i, 0, (int)s.size()) {
		ans += s[i] - 'a' + 1;
		k--;
		if (k == 0) break;
		if (s[i + 1] == s[i] + 1)
			i++;
	}
	cout << (k > 0 ? -1 : ans) << endl;
	return 0;
}