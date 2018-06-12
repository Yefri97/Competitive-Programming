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

char getChar(char c) {
	if (c == 'R') return 'S';
	if (c == 'B') return 'K';
	if (c == 'L') return 'H';
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	string s; cin >> s;
	int n = s.size();
	s.push_back(s.back());
	s.push_back(s.back());
	string ans;
	fori(i, 0, n) {
		if (s[i] != s[i + 1] && s[i + 1] != s[i + 2] && s[i] != s[i + 2]) {
			ans.push_back('C');
			i += 2;
		} else {
			ans.push_back(getChar(s[i]));
		}
	}
	cout << ans << endl;
	return 0;
}