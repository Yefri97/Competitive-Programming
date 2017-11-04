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
	int n;
	while (cin >> n) {
		map<string, int> mapper;
		string s; cin >> s;
		int m = s.size();
		fori(i, 0, m - n)
			mapper[s.substr(i, n)]++;
		string ans;
		int max_val = 0;
		for (auto x : mapper) {
			if (x.second > max_val) {
				max_val = x.second;
				ans = x.first;
			}
		}
		cout << ans << endl;
	}
	return 0;
}