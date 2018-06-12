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
	int n, k;
	while (cin >> n >> k) {
		int x = (1 << n) - k;
		string ans;
		while (x > 1) {
			ans.push_back((x & 1) ? 'R' : 'L');
			x >>= 1;
		}
		reverse(ans.begin(), ans.end());
		cout << "Instructions: " << ans << endl;
	}
	return 0;
}