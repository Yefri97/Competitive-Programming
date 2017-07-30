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
	map<string, int> mapper;
	string s; cin >> s;
	int n = s.size(), ans = n;
	fori(i, 0, n) {
		fori(j, 0, i + 1) {
			string a = s.substr(j, i - j + 1);
			int cnt = 0, len = a.size();
			int k = 0;
			while (k < n - len + 1) {
				if (a == s.substr(k, len)) {
					cnt++;
					k += len;
				} else {
					k++;
				}
			}
			ans = min(ans, n - (cnt * (len - 1)) + len);
		}
	}
	cout << ans << endl;
	return 0;
}