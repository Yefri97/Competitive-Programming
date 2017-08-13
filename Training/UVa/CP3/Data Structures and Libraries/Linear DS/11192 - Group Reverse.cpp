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
	int n;
	while (cin >> n && n) {
		string line; cin >> line;
		int k = (int)line.size() / n;
		string ans;
		fori(i, 0, n) {
			string s = line.substr(i * k, k);
			reverse(s.begin(), s.end());
			ans += s;
		}
		cout << ans << endl;
	}
	return 0;
}