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
	string s; cin >> s;
	string ans;
	fori(i, 0, s.size()) {
		int n = ans.size();
		char ch = s[i];
		if ((n - 1 >= 0 && ch == ans[n - 1]) && ((n - 2 >= 0 && ch == ans[n - 2]) || (n - 2 >= 0 && n - 3 >= 0 && ans[n - 3] == ans[n - 2]))) continue;
		ans.push_back(ch);
	}
	cout << ans << endl;
	return 0;
}