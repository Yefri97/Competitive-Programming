#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl;
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int INF = 1e9;

bool check(int s, int t) {
	int k = (s / 50) % 475;
	fori(i, 0, 25) {
		k = (k * 96 + 42) % 475;
		if ((26 + k) == t) return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int p, x, y; cin >> p >> x >> y;
	bool flag = false;
	for (int curr = x; curr >= y && !flag; curr -= 50)
		if (check(curr, p))
			flag = true;
	if (flag) {
		cout << 0 << endl;
	} else {
		int sh = 1;
		while (true) {
			if (check(x + 100 * sh, p) || check(x + 100 * sh - 50, p))
				break;
			sh++;
		}
		cout << sh << endl;
	}
	return 0;
}