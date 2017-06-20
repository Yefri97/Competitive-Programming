// Palindrome
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

map<char, char> mirror = {{'A', 'A'}, {'E', '3'}, {'H', 'H'}, {'I', 'I'}, {'J', 'L'}, {'M', 'M'}, {'O', 'O'},
													{'S', '2'}, {'T', 'T'}, {'U', 'U'}, {'V', 'V'}, {'W', 'W'}, {'X', 'X'}, {'Y', 'Y'},
													{'Z', '5'}, {'1', '1'}, {'2', 'S'}, {'3', 'E'}, {'5', 'Z'}, {'8', '8'}, {'L', 'J'}};

bool ispalindrome(string s) {
	fori(i, 0, s.size() / 2)
		if (s[i] != s[s.size() - i - 1])
			return false;
	return true;
}

bool ismirror(string s) {
	fori(i, 0, s.size() / 2 + 1) {
		if (mirror[s[s.size() - i - 1]] == 0 || s[i] != mirror[s[s.size() - i - 1]])
			return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	string s;
	while (cin >> s) {
		bool a = ispalindrome(s), b = ismirror(s);
		if (a && b)
			cout << s << " -- is a mirrored palindrome." << endl;
		else if (a && !b)
			cout << s << " -- is a regular palindrome." << endl;
		else if (!a && b)
			cout << s << " -- is a mirrored string." << endl;
		else
			cout << s << " -- is not a palindrome." << endl;
		cout << endl;
	}
	return 0;
}