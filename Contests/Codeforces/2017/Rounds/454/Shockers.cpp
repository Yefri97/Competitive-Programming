#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))
#define sq(x) (x) * (x)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int oo = 1e9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	bitset<26> state; state.set();
	bool flag = false;
	int ans = 0;
	while (n--) {
		bitset<26> bs;
		char q; cin >> q;
		if (q == '?') {
			char s; cin >> s;
			bs.set();
			bs.reset(s - 'a');
			if (n != 0 && flag) ans++; 
		} else if (q == '.') {
			string w; cin >> w;
			bs.set();
			for (char c : w)
				bs.reset(c - 'a');
		} else {
			string w; cin >> w;
			bs.reset();
			for (char c : w)
				bs.set(c - 'a');
			if (flag) ans++;
		}
		state &= bs;
		if (state.count() == 1) flag = true;
	}
	cout << ans << endl;
	return 0;
}