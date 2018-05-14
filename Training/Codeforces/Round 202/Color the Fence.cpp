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
	int k; cin >> k;
	vi v(10);
	fori(i, 1, 10)
		cin >> v[i];
	int mmin = *min_element(v.begin() + 1, v.end());
	int n = k / mmin;
	if (n == 0) { cout << -1 << endl; return 0; }
	string ans = "";
	for (int i = 9; true; i--) {
		if (v[i] == mmin) {
			string s(n, i + '0');
			ans += s;
			break;
		}
		int x = (k - n * mmin) / (v[i] - mmin);
		k -= x * v[i];
		n -= x;
		string s(x, i + '0');
		ans += s;
	}
	cout << ans << endl;
	return 0;
}
