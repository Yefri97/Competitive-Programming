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
	while (getline(cin, line)) {
		line.push_back('.');
		string ans, s;
		for (char c : line) {
			if (isalpha(c)) {
				s.push_back(c);
			} else {
				if (s.size()) {
					char co = tolower(s[0]);
					if (!(co == 'a' || co == 'e' || co == 'i' || co == 'o' || co == 'u')) {
						char coo = s[0];
						s = s.substr(1, s.size() - 1);
						s.push_back(coo);
					}
					s += "ay";
					ans += s;
					s.clear();
				}
				ans.push_back(c);
			}
		}
		ans.pop_back();
		cout << ans << endl;
	}
	return 0;
}