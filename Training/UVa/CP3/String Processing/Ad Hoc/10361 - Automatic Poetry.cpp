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
	int tc; cin >> tc; cin.ignore();
	while (tc--) {
		string l1; getline(cin, l1);
		string l2; getline(cin, l2);
		vector<string> vs(5);
		int curr = 0;
		for (char c : l1) {
			if (c == '<' || c == '>') curr++;
			else vs[curr].push_back(c);
		}
		for (string s : vs) cout << s;
		cout << endl;
		cout << l2.substr(0, l2.size() - 3);
		cout << vs[3] << vs[2] << vs[1] << vs[4] << endl;
	}
	return 0;
}
