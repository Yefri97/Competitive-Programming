// Cipher/Encode/Encrypt/Decode/Decrypt, Easier
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

char tonumber(char c) {
	int n = c - 'A', target;
	if (n <=  2) target = 2;
	else if (n <=  5) target = 3;
	else if (n <=  8) target = 4;
	else if (n <= 11) target = 5;
	else if (n <= 14) target = 6;
	else if (n <= 18) target = 7;
	else if (n <= 21) target = 8;
	else target = 9;
	return target + '0';
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	string s;
	while (cin >> s) {
		fori(i, 0, s.size())
			cout << (s[i] == '1' || s[i] == '0' || s[i] == '-' ? s[i] : tonumber(s[i]));
		cout << endl;
	}
	return 0;
}