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

bool solver(string s) {
	int state = 0;
	fori(i, 0, s.size()) {
		char c = s[i];
		if (state == 0) {
			if (c == '1') state = 1;
			else return false;
		} else if (state == 1) {
			if (c == '1') state = 1;
			else if (c == '4') state = 2;
			else return false;
		} else if (state == 2) {
			if (c == '1') state = 1;
			else if (c == '4') state = 3;
			else return false;
		} else if (state == 3) {
			if (c == '1') state = 1;
			else return false;
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	string line; cin >> line;
	bool ans = solver(line);
	cout << (ans ? "YES" : "NO") << endl;
	return 0;
}