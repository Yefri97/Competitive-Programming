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

int s(int x) {
	int acc = 0;
	while (x) {
		acc += x % 10;
		x /= 10;
	}
	return acc;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int a, b, c; cin >> a >> b >> c;
	vi ans;
	fori(x, 1, 82) {
		ll y = b * pow(x, a) + c;
		if (y <= 0 || y >= 1e9) continue;
		if (x == s(y))
			ans.push_back(y);
	}
	if (ans.size()) {
		cout << ans.size() << endl;
		cout << ans[0];
		fori(i, 1, ans.size())
			cout << " " << ans[i];
		cout << endl;
	} else {
		cout << 0 << endl;
	}
	return 0;
}