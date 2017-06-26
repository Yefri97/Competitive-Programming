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

string to_upper(string s) {
	fori(i, 0, s.size())
		s[i] = toupper(s[i]);
	return s;
}

string to_lower(string s) {
	fori(i, 0, s.size())
		s[i] = tolower(s[i]);
	return s;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	string s; cin >> s;
	int cont = 0;
	fori(i, 0, s.size())
		if (isupper(s[i]))
			cont++;
	if (2 * cont > s.size())
		cout << to_upper(s) << endl;
	else
		cout << to_lower(s) << endl;
	return 0;
}