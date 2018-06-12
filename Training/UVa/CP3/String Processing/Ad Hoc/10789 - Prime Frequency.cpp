#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

bool is_prime(int x) {
	if (x == 1) return false;
	for (int i = 2; i * i <= x; i++)
		if ((x % i) == 0)
			return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int tc; cin >> tc;
	fori(t, 0, tc) {
		map<char, int> mapper;
		int f = 0;
		string s; cin >> s;
		for (char c : s)
			mapper[c]++;
		cout << "Case " << t + 1 << ": ";
		for (ii x : mapper) {
			if (is_prime(x.second)) {
				f = true;
				cout << (char)x.first;
			}
		}
		if (!f) cout << "empty";
		cout << endl;
	}
	return 0;
}
