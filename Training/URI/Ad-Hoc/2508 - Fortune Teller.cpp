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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	string name; 
	while (getline(cin, name)) {
		int ans = 0;
		fori(i, 0, name.size()) {
			char c = name[i];
			if (c == ' ') continue;
			int x = (tolower(c) - 'a') % 9 + 1;
			ans += x;
		}
		while (ans / 10) {
			int acc = 0;
			while (ans) {
				acc += ans % 10;
				ans /= 10;
			}
			ans = acc;
		}
		cout << ans << endl;
	}
	return 0;
}