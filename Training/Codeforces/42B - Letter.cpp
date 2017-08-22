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

int toint(char c) { return isupper(c) ? c - 'A' + 26 : c - 'a'; }

bool solver(string heading, string text) {
	vi freq(52);
	fori(i, 0, heading.size()) {
		char c = heading[i];
		if (c == ' ') continue;
		freq[toint(c)]++;
	}
	fori(i, 0, text.size()) {
		char c = text[i];
		if (c == ' ') continue;
		if (freq[toint(c)] > 0) freq[toint(c)]--;
		else return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	string heading, text;
	getline(cin, heading);
	getline(cin, text);
	bool ans = solver(heading, text);
	cout << (ans ? "YES" : "NO") << endl;
	return 0;
}