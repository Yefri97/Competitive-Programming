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

int solver(string s) {
	int target = 0, state = 0;
	fori(i, 0, s.size()) {
		char c = s[i];
		if (state == 0) {
			if (c == '0')
				state = 0;
			else if (c == '1')
				state = 1;
			else
				state = 0;
		} else if (state == 1) {
			if (c == '0')
				state = 2;
			else if (c == '1')
				state = 1;
			else
				state = 0;
		} else if (state == 2) {
			if (c == '0')
				state = 2;
			else if (c == '1') {
				state = 1;
				target++;
			} else {
				state = 0;
			}
		}
	}
	return target;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int q; cin >> q;
	while (q--) {
		string s; cin >> s;
		int result = solver(s);
		cout << result << endl;
	}
	return 0;
}