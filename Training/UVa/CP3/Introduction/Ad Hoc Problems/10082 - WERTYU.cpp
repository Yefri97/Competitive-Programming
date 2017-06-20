// Interesting Real Life Problems, Easier
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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	string decode = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
	string line;
	while (getline(cin, line)) {
		string result;
		fori(i, 0, line.size()) {
			char c = line[i];
			int pos = decode.find(c);
			if (pos != -1)
				result.push_back(decode[pos - 1]);
			else
				result.push_back(c);
		}
		cout << result << endl;
	}
	return 0;
}