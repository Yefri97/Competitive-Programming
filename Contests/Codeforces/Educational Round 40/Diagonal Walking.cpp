#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9, MN = 110;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	string s; cin >> s;
	int ans = n;
	fori(i, 0, n - 1) {
		if (s[i] == 'U' && s[i + 1] == 'R' || s[i] == 'R' && s[i + 1] == 'U') {
			ans--;
			i++;
		}
	}
	cout << ans << endl;
	return 0;
}
