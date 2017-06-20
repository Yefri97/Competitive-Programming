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
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		if (s.size() > 3) {
			cout << 3 << endl;
		} else {
			if (((s[0] != 'o') + (s[1] != 'n') + (s[2] != 'e')) <= 1)
				cout << 1 << endl;
			else
				cout << 2 << endl;
		}
	}
	return 0;
}