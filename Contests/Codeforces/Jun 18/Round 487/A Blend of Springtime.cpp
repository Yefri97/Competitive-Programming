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
	string abc = "ABC";
	int ok = 0;
	do {
		ok |= (s.find(abc) < s.size());
	} while (next_permutation(abc.begin(), abc.end()));
	cout << (ok ? "YES" : "NO") << endl;
	return 0;
}
