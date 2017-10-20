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

const int oo = 1e9, k = 131071;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	char c;
	while (cin >> c) {
		int ans = c - '0';
		while (cin >> c && c != '#')
			ans = (ans * 2 + (c - '0')) % k;
		cout << (ans == 0 ? "YES" : "NO") << endl;
	}
	return 0;
}