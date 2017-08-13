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

string process(string s) {
	string target;
	for (char c : s)
		target.push_back(tolower(c));
	return target;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	set<string> dict;
	string line;
	while (getline(cin, line)) {
		line.push_back('#');
		string s;
		for (char c : line) {
			if (!isalpha(c)) {
				if (s.size())
					dict.insert(process(s));
				s.clear();
			} else {
				s.push_back(c);
			}
		}
	}
	for (string s : dict)
		cout << s << endl;
	return 0;
}