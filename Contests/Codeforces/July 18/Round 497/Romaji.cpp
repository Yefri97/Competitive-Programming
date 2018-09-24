#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

string vowels = "aeiou";

int isvowel(char c) { return vowels.find(c) < 5; }

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	string s; cin >> s;
	int n = s.size();
	int ok = 1;
	fori(i, 0, n) {
		if (!isvowel(s[i]))
			ok &= (s[i] == 'n' || i + 1 < n && isvowel(s[i + 1]));
	}
	cout << (ok ? "YES" : "NO") << endl;
	return 0;
}
