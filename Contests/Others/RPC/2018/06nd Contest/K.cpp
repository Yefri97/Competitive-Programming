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
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		int n = s.size(), k = 0;
		while (k < n && s[k] == 'a') k++;
		int ans = (k > 0);
		while (k < n) {
			while (k < n && s[k] == 'b') k++;
			if (k == n) break;
			while (k < n && s[k] == 'a') k++;
			ans += 2;
		}
		cout << ans << endl;
	}
	return 0;
}
