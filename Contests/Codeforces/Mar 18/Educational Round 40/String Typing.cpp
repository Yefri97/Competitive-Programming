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
	int ans = n;
	for (int i = 1; 2 * i <= n; i++) {
		if (s.substr(0, i) == s.substr(i, i))
			ans = n - i + 1;
	}
	cout << ans << endl;
	return 0;
}
