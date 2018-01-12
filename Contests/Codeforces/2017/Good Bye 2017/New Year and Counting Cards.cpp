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
	string line; cin >> line;
	int ans = 0;
	for (char c : line)
		ans += (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || (isdigit(c) && (c - '0') % 2));
	cout << ans << endl;
	return 0;
}