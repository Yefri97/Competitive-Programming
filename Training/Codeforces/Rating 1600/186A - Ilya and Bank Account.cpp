#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))
#define sq(x) (x) * (x)
#define toint(s) atoi(s.c_str())

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int oo = 1e9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	string n; cin >> n;
	if (n[0] != '-') {
		cout << n << endl;
	} else {
		char a = n.back(); n.pop_back();
		int x = toint(n);
		char b = n.back(); n.pop_back();
		n.push_back(a);
		int y = toint(n);
		cout << max(x, y) << endl;;
	}
	return 0;
}