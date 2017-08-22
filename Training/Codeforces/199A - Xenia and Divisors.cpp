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
	vi freq(8);
	int n; cin >> n;
	fori(i, 0, n) {
		int x; cin >> x;
		freq[x]++;
	}
	int ga = min(freq[1], min(freq[2], freq[4]));
	freq[1] -= ga; freq[2] -= ga; freq[4] -= ga;
	int gb = min(freq[1], min(freq[2], freq[6]));
	freq[1] -= gb; freq[2] -= gb; freq[6] -= gb;
	int gc = min(freq[1], min(freq[3], freq[6]));
	freq[1] -= gc; freq[3] -= gc; freq[6] -= gc;
	bool ans = true;
	fori(i, 1, 8)
		ans &= (freq[i] == 0);
	if (ans) {
		while (ga--) cout << 1 << " " << 2 << " " << 4 << endl;
		while (gb--) cout << 1 << " " << 2 << " " << 6 << endl;
		while (gc--) cout << 1 << " " << 3 << " " << 6 << endl;
	} else {
		cout << -1 << endl;
	}
	return 0;
}