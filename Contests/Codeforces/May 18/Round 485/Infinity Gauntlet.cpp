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
	map<string, string> mapper = {
		{"purple", "Power"},
		{"green", "Time"},
		{"blue", "Space"},
		{"orange", "Soul"},
		{"red", "Reality"},
		{"yellow", "Mind"}
	};
	int n; cin >> n;
	fori(i, 0, n) {
		string s; cin >> s;
		mapper.erase(s);
	}
	cout << mapper.size() << endl;
	for (auto m : mapper)
		cout << m.second << endl;
	return 0;
}
