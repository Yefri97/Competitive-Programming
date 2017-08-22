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
	string s, ans; cin >> s;
	int n = s.size(), pos = 0;
	while (pos < n) {
		if (s[pos] == '0') break;
		pos++;
	}
	if (pos == n) s.erase(s.begin() + n - 1);
	else s.erase(s.begin() + pos);
	cout << s << endl;
	return 0;
}