// String/Pattern
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

int solver(string s) {
	int target = 0, state = 0;
	fori(i, 0, s.size()) {
		char c = s[i];
		if (state == 0) {
			if (isalpha(c)) {
				target++;
				state = 1 - state;
			}
		} else {
			if (!isalpha(c))
				state = 1 - state;
		}
	}
	return target;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	string line;
	while (getline(cin, line)) {
		int result = solver(line);
		cout << result << endl;
	}
	return 0;
}