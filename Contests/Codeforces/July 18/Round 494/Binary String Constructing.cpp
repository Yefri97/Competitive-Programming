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
	int a, b, x; cin >> a >> b >> x;
	int sw = 0;
	if (a < b) {
		sw = 1;
		swap(a, b);
	}
	int n = a + b;
	string ans(n, '0');
	int idx = (x + 1) % 2;
	if (x % 2) x--;
	else x -= 2;
	fori(i, 0, b) {
		ans[idx] = '1';
		if (x > 0) {
			idx += 2;
			x -= 2;
		} else {
			idx++;
		}
	}
	fori(i, 0, n)
		ans[i] = (sw ? 1 - (ans[i] - '0') + '0' : ans[i]);
	cout << ans << endl;
	return 0;
}
