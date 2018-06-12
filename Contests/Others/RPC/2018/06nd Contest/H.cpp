#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

string doit(string x) {
	int f = isupper(x[0]);
	reverse(x.begin(), x.end());
	if (f && x.size() > 1) {
		x[0] = toupper(x[0]);
		x[x.size() - 1] = tolower(x[x.size() - 1]);
	}
	return x;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t; cin.ignore();
	while (t--) {
		string s, x;
		while (getline(cin, s) && s != "*") {
			for (char c : s) {
				if (!isalpha(c)) {
					cout << doit(x) << c;
					x.clear();
				} else {
					x.push_back(c);
				}
			}
			if (x.size() > 0) cout << doit(x);
			x.clear();
			cout << endl;
		}
		if (t) cout << endl;
	}
	return 0;
}
