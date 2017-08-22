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
	vector<int> freq(26);
	string s; cin >> s;
	fori(i, 0, s.size())
		freq[s[i] - 'a']++;
	int x = 0;
	fori(i, 0, 26)
		x += (freq[i] % 2);
	if (x > 1) {
		cout << (x % 2 == 0 ? "Second" : "First") << endl;
	} else {
		cout << "First" << endl;
	}
	return 0;
}