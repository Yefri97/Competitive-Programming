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

bool check(string s) {
	int id = 0;
	vi v(3);
	for (char c : s) {
		if (c != 'M' && c != 'E' && c != '?' || c == 'M' && id != 0 || c == 'E' && id != 1) return false;
		if (c == 'M' || c == 'E') id++;
		else v[id]++;
	}
	return v[0] >= 1 && v[1] >= 1 && v[0] + v[1] == v[2];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		bool ans = check(s);
		cout << (!ans ? "no-" : "") << "theorem" << endl;
	}
	return 0;
}