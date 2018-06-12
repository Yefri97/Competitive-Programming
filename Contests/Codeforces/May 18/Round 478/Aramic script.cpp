#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	set<string> dict;
	fori(i, 0, n) {
		string s; cin >> s;
		sort(s.begin(), s.end());
		s.resize(distance(s.begin(), unique(s.begin(), s.end())));
		dict.insert(s);
	}
	cout << dict.size() << endl;
	return 0;
}
