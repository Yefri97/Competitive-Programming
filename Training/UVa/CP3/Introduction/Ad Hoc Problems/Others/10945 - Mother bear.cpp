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
	string line;
	while (getline(cin, line) && line != "DONE") {
		string s;
		for (char c : line)
			if (isalpha(c))
				s.push_back(tolower(c));
		int n = s.size(), ans = 1;
		fori(i, 0, n)
			ans &= (s[i] == s[n - i - 1]);
		if (ans) cout << "You won't be eaten!" << endl;
		else cout << "Uh oh.." << endl;
	}
	return 0;
}