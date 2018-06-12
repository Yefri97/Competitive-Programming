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
	int n; cin >> n;
	string ans;
	while (n) {
		if (n % 2) {
			n = (n - 1) / 2;
			ans.push_back('A');
		} else {
			n = (n - 2) / 2;
			ans.push_back('B');
		}
	}
	reverse(ans.begin(), ans.end());
	cout << ans << endl;
	return 0;
}