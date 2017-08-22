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

int n;
string s;

bool check(int l) {
	if (n % l) return false;
	for (int i = 1; i * l < n; i++)
		if (s.substr(0, l) != s.substr(i * l, l))
			return false;
	return true;
}

int solver() {
	fori(i, 1, n+1)
		if (check(i))
			return i;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> s;
		n = s.size();
		int ans = solver();
		cout << ans << endl;
		if (t) cout << endl;
	}
	return 0;
}