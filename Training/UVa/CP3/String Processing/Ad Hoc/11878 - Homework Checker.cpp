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
	string s;
	int ans = 0;
	while (cin >> s) {
		int n = s.size();
		int a = 0;
		while (s[a] != '+' && s[a] != '-') a++;
		int b = a;
		while (s[b] != '=') b++;
		int x = atoi(s.substr(0, a).c_str());
		int y = atoi(s.substr(a + 1, b - (a + 1)).c_str());
		if (s.substr(b + 1, n - (b + 1)) != "?") {
			int z = atoi(s.substr(b + 1, n - (b + 1)).c_str());
			if (s[a] == '+')
				ans += (x + y == z);
			else
				ans += (x - y == z);
		}
	}
	cout << ans << endl;
	return 0;
}