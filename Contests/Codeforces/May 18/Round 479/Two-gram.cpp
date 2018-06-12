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
	string s; cin >> s;
	int mmax = 0;
	string ans;
	fori(i, 0, n - 1) {
		int cnt = 0;
		fori(j, 0, n - 1) {
			cnt += (s.substr(i, 2) == s.substr(j, 2));
		}
		if (cnt > mmax) {
			mmax = cnt;
			ans = s.substr(i, 2);
		}
	}
	cout << ans << endl;
	return 0;
}
