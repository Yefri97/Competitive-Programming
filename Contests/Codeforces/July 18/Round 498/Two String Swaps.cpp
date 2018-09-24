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
	int n; cin >> n;
	string a, b; cin >> a >> b;
	int ans = 0;
	fori(i, 0, n / 2) {
		set<char> dict;
		dict.insert(a[i]);
		dict.insert(a[n - i - 1]);
		dict.insert(b[i]);
		dict.insert(b[n - i - 1]);
		if (SZ(dict) == 4) ans += 2;
		else if (SZ(dict) == 3) ans += (a[i] == a[n - i - 1] ? 2 : 1);
		else if (SZ(dict) == 2) ans += ((a[i] != a[n - i - 1]) ^ (b[i] != b[n - i - 1]));
	}
	if (n % 2)
		ans += (a[n / 2] != b[n / 2]);
	cout << ans << endl;
	return 0;
}
