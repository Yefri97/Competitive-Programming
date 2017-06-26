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

string letters = "qwertyuiop[]asdfghjkl;'\\zxcvbnm,./";

char decode(char c) {
	int n = letters.find(tolower(c));
	return n == -1 ? c : letters[n - 2];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	string line;
	while (getline(cin, line)) {
		string result;
		fori(i, 0, line.size()) {
			char c = line[i];
			result.push_back(decode(c));
		}
		cout << result << endl;
	}
	return 0;
}