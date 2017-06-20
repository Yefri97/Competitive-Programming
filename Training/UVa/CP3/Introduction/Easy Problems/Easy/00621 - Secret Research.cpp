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
	int n; cin >> n;
	while (n--) {
		string s; cin >> s;
		if (s == "1" || s == "4" || s == "78")
			cout << "+" << endl;
		else if (s.size() > 2 && s[s.size() - 2] == '3' && s[s.size() - 1] == '5')
			cout << "-" << endl;
		else if (s[0] == '9' && s[s.size() - 1] == '4')
			cout << "*" << endl;
		else
			cout << "?" << endl;
	}
	return 0;
}