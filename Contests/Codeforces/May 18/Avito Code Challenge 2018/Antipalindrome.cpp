#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	string s; cin >> s;
	int n = s.size();
	int a = 1, b = 1;
	fori(i, 0, n) {
		a &= (s[i] == s[0]);
		b &= (s[i] == s[n - i - 1]);
	}
	if (a)
		cout << 0 << endl;
	else {
		cout << (b ? n - 1 : n) << endl;
	}
	return 0;
}
