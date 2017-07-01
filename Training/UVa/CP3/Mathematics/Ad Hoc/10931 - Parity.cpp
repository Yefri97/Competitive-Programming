// Base Number Variants
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
	int n;
	while (cin >> n && n) {
		string bin;
		int ans = 0, x = n;
		while (x > 0) {
			ans += x & 1;
			bin.push_back((x & 1) + '0');
			x >>= 1;
		}
		reverse(bin.begin(), bin.end());
		cout << "The parity of " << bin << " is " << ans << " (mod 2)." << endl;
	}
	return 0;
}